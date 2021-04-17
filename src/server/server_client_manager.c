/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 server_client_manager.c
*/

#include "server.h"

int server_client_manager(app_t *app, connection_t *client)
{
    bool is_error;
    cmd_t *request = get_request(client, &is_error);
    int exit_status = EXIT_SUCCESS;

    if (!request && is_error) {
        return EXIT_FAILURE;
    } else if (!request) {
        return EXIT_SUCCESS;
    }
    exit_status = server_execute_cmd(app, client, request);
    cmd_destroy(request);
    return exit_status;
}