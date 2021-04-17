/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 connection_destroy.c
*/

#include "server.h"
#include "socket.h"

int connection_destroy(connection_t *conn)
{
    if (socket_close(&conn->sock))
        return EXIT_FAILURE;
    free(conn->workdir);
    if (conn->channel_list != NULL) {
        if (dchannel_list_destroy(conn->channel_list) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    free(conn);
    return EXIT_SUCCESS;
}