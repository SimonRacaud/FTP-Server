/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 send_raw_message.c
*/

#include "server.h"
#include "socket.h"

int send_raw_message(socket_t *sock, const char *message)
{
    if (socket_send(sock, message) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}