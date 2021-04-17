/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 app_loop.c
*/

#include "app.h"
#include "server.h"
#include "socket.h"

int app_loop(app_t *app)
{
    server_t *serv = &app->server;

    while (app->loop) {
        if (socket_server_select(&serv->select, serv->clients, &serv->sock))
            return EXIT_SUCCESS;
        if (serv->select.status == 0)
            continue;
        if (FD_ISSET(serv->sock.fd, &serv->select.read_fds)
            && server_connect_client(serv) == EXIT_FAILURE) {
            return EXIT_FAILURE;
        }
        if (!serv->select.status)
            continue;
        if (server_dchannel_requests_process(&serv->select, serv->clients))
            return EXIT_FAILURE;
        if (server_client_requests_process(app, serv) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}