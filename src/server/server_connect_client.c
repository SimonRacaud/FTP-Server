/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 server_connect_client.c
*/

#include "server.h"

int server_connect_client(server_t *server)
{
    connection_t *client = connection_create(server->sock.fd);

    if (!client)
        return EXIT_FAILURE;
    if (connection_list_push(client, &server->clients) == EXIT_FAILURE)
        return EXIT_FAILURE;
    server->select.status--;
    return send_response(&client->sock, C220, "Service ready for new user.");
}