/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 20/04/2021 command_list.c
*/

#include "app.h"
#include "server.h"
#include "utility.h"

static int command_core(
    const char *pathname, connection_t *client, socket_t *data_sock)
{
    char buffer[READ_SIZE + 1] = {0};
    char *command = strdup("/bin/ls -l ");
    FILE *file;

    if (pathname)
        command = strconcat(command, pathname);
    file = popen(command, "r");
    free(command);
    if (file == NULL) {
        send_response(
            &client->sock, C426, "Connection closed; transfer aborted.");
        return EXIT_FAILURE;
    }
    while (fgets(buffer, READ_SIZE, file) != NULL) {
        send_raw_message(data_sock, buffer);
    }
    fclose(file);
    return EXIT_SUCCESS;
}

static void actions_in_child_process(
    connection_t *client, data_channel_t *ptr, const char *pathname)
{
    int status = command_core(pathname, client, &ptr->sock);

    if (status == EXIT_SUCCESS)
        send_response(&client->sock, C226, "Directory send OK.");
    dchannel_list_remove(&client->channel_list, ptr);
    exit(EXIT_SUCCESS);
}

static char *get_absolute_filepath(connection_t *client, const char *pathname)
{
    char *path = NULL;

    if (pathname) {
        path = edit_dirpath(CLIENT_HOME(client), client->workdir, pathname);
        if (!path)
            return NULL;
        if (access(path, R_OK) == -1) {
            free(path);
            return NULL;
        }
        return path;
    }

    return strdup(client->workdir);
}

int command_list(
    __attribute__((unused)) app_t *app, connection_t *client, cmd_t *request)
{
    char *pathname = get_absolute_filepath(client, request->argv);
    data_channel_t *ptr = dchannel_get_free_channel(client->channel_list);
    pid_t pid;

    if (!ptr) {
        return send_response(&client->sock, C425, "Use PORT or PASV first.");
    } else if (!pathname && request->argv != NULL) {
        return send_response(&client->sock, C500, "Invalid pathname.");
    }
    pid = dchannel_prepare(client, ptr);
    if (pid == -1)
        return send_response(&client->sock, C500, "An error occured.");
    if (pid == 0) {
        actions_in_child_process(client, ptr, pathname);
    }
    free(pathname);
    return EXIT_SUCCESS;
}