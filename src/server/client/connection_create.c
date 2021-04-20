/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 connection_create.c
*/

#include "server.h"
#include "socket.h"

connection_t *connection_create(int server_fd)
{
    connection_t *conn = malloc(sizeof(connection_t));

    if (!conn)
        return NULL;
    if (socket_server_connect(&conn->sock, server_fd))
        return NULL;
    conn->session.account_ptr = NULL;
    conn->session.is_logged = false;
    conn->session.username = NULL;
    conn->channel_list = NULL;
    conn->read_buffer = NULL;
    conn->workdir = strdup("");
    if (!conn->workdir)
        return NULL;
    return conn;
}