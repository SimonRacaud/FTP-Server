/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 command_quit.c
*/

#include "app.h"
#include "server.h"

int command_quit(
    app_t *app, connection_t *client, __attribute__((unused)) cmd_t *request)
{
    app->loop = false;
    if (send_response(&client->sock, C221, "Goodbye."))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}