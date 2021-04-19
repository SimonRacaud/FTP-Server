/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 19/04/2021 command_pwd.c
*/

#include "app.h"
#include "server.h"

int command_pwd(__attribute__((unused)) app_t *app, connection_t *client,
    __attribute__((unused)) cmd_t *request)
{
    const char *init = "257 ";
    char *message =
        malloc(sizeof(char) * (strlen(init) + strlen(client->workdir) + 2));

    if (!message)
        return EXIT_FAILURE;
    strcpy(message, init);
    strcat(message, client->workdir);
    strcat(message, "\n");
    if (send_raw_message(&client->sock, message)) {
        free(message);
        return EXIT_FAILURE;
    }
    free(message);
    return EXIT_SUCCESS;
}