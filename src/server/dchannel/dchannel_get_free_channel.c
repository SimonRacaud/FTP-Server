/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 20/04/2021 dchannel_have_free_channel.c
*/

#include "server.h"

data_channel_t *dchannel_get_free_channel(data_channel_t **list)
{
    for (size_t i = 0; list[i] != NULL; i++) {
        if (list[i]->used == false) {
            return list[i];
        }
    }
    return NULL;
}