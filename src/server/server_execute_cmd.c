/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 server_execute_cmd.c
*/

#include "server.h"
#include "utility.h"

extern const command_t COMMANDS[];

static int call_command(
    app_t *app, connection_t *client, cmd_t *request, size_t idx)
{
    if (COMMANDS[idx].need_auth == true
        && client->session.is_logged == false) {
        if (send_response(
                &client->sock, C530, "Please login with USER and PASS."))
            return EXIT_FAILURE;
        return EXIT_SUCCESS;
    }
    if (COMMANDS[idx].func) {
        if (COMMANDS[idx].case_insensitive == true && request->argv)
            str_to_upper(request->argv);
        return COMMANDS[idx].func(app, client, request);
    }
    fprintf(
        stderr, "Warning: %s command not implemented.\n", COMMANDS[idx].label);
    return EXIT_SUCCESS;
}

int server_execute_cmd(app_t *app, connection_t *client, cmd_t *request)
{
    int exit_status = EXIT_SUCCESS;

    for (size_t i = 0; COMMANDS[i].label != NULL; i++) {
        if (strcmp(COMMANDS[i].label, request->label) == 0) {
            exit_status = call_command(app, client, request, i);
            return exit_status;
        }
    }
    if (send_response(&client->sock, C500, "Unknown command."))
        return EXIT_FAILURE;
    return exit_status;
}