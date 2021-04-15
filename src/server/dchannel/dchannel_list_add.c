/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 dchannel_list_add.c
*/

#include "server.h"

int dchannel_list_add(data_channel_t *node, connection_t *client)
{
    size_t size = 0;

    if (client->channel_list != NULL) {
        for (; client->channel_list[size] != NULL; size++);
        client->channel_list = realloc(
            client->channel_list, sizeof(data_channel_t *) * (size + 2));
        if (!client->channel_list)
            return EXIT_FAILURE;
        client->channel_list[size] = node;
        client->channel_list[size + 1] = NULL;
    } else {
        client->channel_list = calloc(1, sizeof(data_channel_t *) * 2);
        if (!client->channel_list)
            return EXIT_FAILURE;
        client->channel_list[0] = node;
    }
    return EXIT_SUCCESS;
}