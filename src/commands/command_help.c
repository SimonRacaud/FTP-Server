/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 command_help.c
*/

#include "app.h"
#include "server.h"

extern const command_t COMMANDS[];

const char *HELP_INIT = "214-The following commands are recognized.\n";

static void show_commands(socket_t *sock)
{
    for (size_t i = 0; COMMANDS[i].label != NULL; i++) {
        send_raw_message(sock, " ");
        if (i && i % 14 == 0) {
            send_raw_message(sock, "\n");
        }
        send_raw_message(sock, COMMANDS[i].label);
        if (strlen(COMMANDS[i].label) != 4) {
            send_raw_message(sock, " ");
        }
    }
    send_raw_message(sock, "\n");
}

int command_help(__attribute__((unused)) app_t *app, connection_t *client,
    __attribute__((unused)) cmd_t *request)
{
    if (send_raw_message(&client->sock, HELP_INIT))
        return EXIT_FAILURE;
    show_commands(&client->sock);
    if (send_response(&client->sock, C214, "Help OK."))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}