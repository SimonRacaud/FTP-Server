/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 19/04/2021 command_cdup.c
*/

#include "app.h"
#include "server.h"
#include "utility.h"

int command_cdup(__attribute__((unused)) app_t *app, connection_t *client,
    __attribute__((unused)) cmd_t *request)
{
    const char *home = CLIENT_HOME(client);
    char *result;

    result = edit_dirpath(home, client->workdir, "../");
    if (result != NULL) {
        free(client->workdir);
        client->workdir = result;
    }
    if (send_response(&client->sock, C250, "Directory successfully changed."))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
