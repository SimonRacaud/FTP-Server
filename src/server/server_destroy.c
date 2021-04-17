/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 server_destroy.c
*/

#include "socket.h"
#include "server.h"

static int destroy_clients(server_t *server)
{
    if (connection_list_destroy(server->clients) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int server_destroy(server_t *server)
{
    if (socket_close(&server->sock) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (destroy_clients(server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}