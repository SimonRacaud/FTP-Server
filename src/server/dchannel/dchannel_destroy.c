/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 dchannel_destroy.c
*/

#include "server.h"
#include "socket.h"

int dchannel_destroy(data_channel_t *dchannel)
{
    if (socket_close(&dchannel->sock))
        return EXIT_FAILURE;
    free(dchannel);
    return EXIT_SUCCESS;
}