/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 get_request.c
*/

#include "server.h"
#include "socket.h"

cmd_t *get_request(connection_t *client, bool *is_error)
{
    char *command = socket_receive(&client->sock);
    cmd_t *cmd;

    if (!command) {
        *is_error = true;
        return NULL;
    }
    if (command[0] == '\0') {
        *is_error = false;
        free(command);
        return NULL;
    }
    cmd = cmd_create(command);
    free(command);
    if (cmd == NULL)
        *is_error = true;
    return cmd;
}