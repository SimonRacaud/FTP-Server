/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 command_help.c
*/

#include "app.h"
#include "server.h"

extern const command_t COMMANDS[];

const char *HELP_INIT_ALL = "214-The following commands are recognized.\n";
const char *HELP_INIT_ARG = "214-Command description.\n";

static void show_available_commands(socket_t *sock)
{
    send_raw_message(sock, HELP_INIT_ALL);
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

static bool show_specific_command(socket_t *sock, const char *cmd_name)
{
    send_raw_message(sock, HELP_INIT_ARG);
    for (size_t i = 0; COMMANDS[i].label != NULL; i++) {
        if (strcmp(cmd_name, COMMANDS[i].label) == 0) {
            send_raw_message(sock, COMMANDS[i].label);
            send_raw_message(sock, " ");
            send_raw_message(sock, COMMANDS[i].description);
            send_raw_message(sock, "\n");
            return true;
        }
    }
    send_response(sock, C500, "Unknown command.");
    return false;
}

int command_help(__attribute__((unused)) app_t *app, connection_t *client,
    __attribute__((unused)) cmd_t *request)
{
    if (request->argv == NULL) {
        show_available_commands(&client->sock);
    } else {
        if (!show_specific_command(&client->sock, request->argv))
            return EXIT_SUCCESS;
    }
    if (send_response(&client->sock, C214, "Help OK."))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}