/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 get_request.c
*/

#include "server.h"
#include "socket.h"
#include "utility.h"

char *check_command(char *command, connection_t *client, bool empty)
{
    if (!command && empty) {
        command = strdup(LOGOUT_CMD);
    } else if (!command) {
        return NULL;
    }
    if (is_empty(command)) {
        free(command);
        send_response(&client->sock, C500, "Empty line.");
        return NULL;
    }
    if (command[0] == '\0') {
        free(command);
        return NULL;
    }
    return command;
}

cmd_t *get_request(connection_t *client, bool *is_error)
{
    bool empty = false;
    char *command =
        socket_receive(&client->sock, &client->read_buffer, &empty);
    cmd_t *cmd;

    *is_error = false;
    command = check_command(command, client, empty);
    if (!command)
        return NULL;
    cmd = cmd_create(command);
    free(command);
    if (cmd == NULL)
        *is_error = true;
    return cmd;
}

bool have_available_command_in_buffer(connection_t *client)
{
    if (client->read_buffer && find_newline(client->read_buffer) != -1) {
        return true;
    }
    return false;
}