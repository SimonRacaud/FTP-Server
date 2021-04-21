/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 20/04/2021 command_stor.c
*/

#include "app.h"
#include "server.h"
#include "utility.h"

static int command_core(FILE *file, socket_t *data_sock)
{
    char buffer[READ_SIZE + 1] = {0};
    ssize_t read_len;

    do {
        read_len = read(data_sock->fd, buffer, READ_SIZE);
        buffer[read_len] = '\0';
        if (read_len > 0) {
            fputs(buffer, file);
        }
    } while (read_len == READ_SIZE);
    return EXIT_SUCCESS;
}

static void actions_in_child_process(
    connection_t *client, data_channel_t *ptr, FILE *file)
{
    int status = command_core(file, &ptr->sock);

    if (status == EXIT_SUCCESS) {
        send_response(&client->sock, C226, "Transfer complete.");
    }
    dchannel_list_remove(&client->channel_list, ptr);
    exit(EXIT_SUCCESS);
}

static char *get_absolute_filepath(connection_t *client, const char *pathname)
{
    char *filepath = NULL;

    if (pathname) {
        filepath = strdup(client->workdir);
        filepath = strconcat(filepath, "/");
        filepath = strconcat(filepath, pathname);
        if (!filepath)
            return NULL;
        return filepath;
    }
    return NULL;
}

static FILE *open_file(const char *pathname, connection_t *client)
{
    FILE *file = fopen(pathname, "w");

    if (file == NULL) {
        send_response(&client->sock, C550, "Failed to open file.");
    }
    return file;
}

int command_stor(
    __attribute__((unused)) app_t *app, connection_t *client, cmd_t *request)
{
    char *filepath = get_absolute_filepath(client, request->argv);
    data_channel_t *ptr = dchannel_get_free_channel(client->channel_list);
    pid_t pid;
    FILE *file;

    if (!ptr) {
        return send_response(&client->sock, C425, "Use PORT or PASV first.");
    } else if (!filepath)
        return send_response(&client->sock, C550, "Bad argument.");
    file = open_file(filepath, client);
    if (!file)
        return EXIT_SUCCESS;
    pid = dchannel_prepare(client, ptr);
    if (pid == -1)
        return send_response(&client->sock, C500, "An error occurred.");
    if (pid == 0)
        actions_in_child_process(client, ptr, file);
    free(filepath);
    fclose(file);
    return EXIT_SUCCESS;
}