/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 server_client_requests_process.c
*/

#include "server.h"
#include "socket.h"

int server_client_requests_process(app_t *app, server_t *server)
{
    for (size_t i = 0; server->clients && server->clients[i] != NULL; i++) {
        if (TO_PROCESS(server->clients[i], server->select.read_fds)
            && server_client_manager(app, server->clients[i])
                == EXIT_FAILURE) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}