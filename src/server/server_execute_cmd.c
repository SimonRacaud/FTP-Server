/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 server_execute_cmd.c
*/

#include "server.h"

extern const command_t COMMANDS[];

static int call_command(
    app_t *app, connection_t *client, cmd_t *request, size_t idx)
{
    if (COMMANDS[idx].func) {
        return COMMANDS[idx].func(app, client, request);
    }
    fprintf(
        stderr, "Warning: %s command not implemented.\n", COMMANDS[idx].label);
    return EXIT_SUCCESS;
}

int server_execute_cmd(app_t *app, connection_t *client, cmd_t *request)
{
    int exit_status = EXIT_FAILURE;

    for (size_t i = 0; COMMANDS[i].label != NULL; i++) {
        if (strcmp(COMMANDS[i].label, request->label) == 0) {
            exit_status = call_command(app, client, request, i);
            return exit_status;
        }
    }
    // TODO : command not found
    printf("debug: command (%s) not found\n", request->label);
    return exit_status;
}