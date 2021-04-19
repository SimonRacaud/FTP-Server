/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 19/04/2021 command_cwd.c
*/

#include "app.h"
#include "server.h"
#include "utility.h"

int command_cwd(
    __attribute__((unused)) app_t *app, connection_t *client, cmd_t *request)
{
    const char *home = CLIENT_HOME(client);
    const char *destdir = request->argv;
    char *result;

    if (!destdir) {
        if (send_response(&client->sock, C550, "Failed to change directory."))
            return EXIT_FAILURE;
        return EXIT_SUCCESS;
    }
    result = edit_dirpath(home, client->workdir, destdir);
    if (result == NULL) {
        if (send_response(&client->sock, C550, "Failed to change directory."))
            return EXIT_FAILURE;
        return EXIT_SUCCESS;
    }
    free(client->workdir);
    client->workdir = result;
    if (send_response(&client->sock, C250, "Directory successfully changed."))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}