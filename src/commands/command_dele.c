/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 19/04/2021 command_dele.c
*/

#include "app.h"
#include "server.h"

int command_dele(
    __attribute__((unused)) app_t *app, connection_t *client, cmd_t *request)
{
    char *filename = request->argv;

    if (!filename) {
        if (send_response(&client->sock, C500, "No filename."))
            return EXIT_FAILURE;
        return EXIT_SUCCESS;
    }
    if (chdir(client->workdir) == -1) {
        if (send_response(&client->sock, C500, "An error occured, chdir."))
            return EXIT_FAILURE;
    } else if (remove(filename) == -1) {
        if (send_response(&client->sock, C500, "An error occured."))
            return EXIT_FAILURE;
    } else {
        if (send_response(&client->sock, C250, "File deleted."))
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}