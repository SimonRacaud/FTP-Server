/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 20/04/2021 dchannel_clean.c
*/

#include "server.h"

int dchannel_list_clean(data_channel_t ***list_ptr)
{
    data_channel_t **list = *list_ptr;

    for (size_t i = 0; list && list[i] != NULL; i++) {
        if (list[i]->used == false) {
            dchannel_list_remove(list_ptr, list[i]);
        }
    }
    return EXIT_SUCCESS;
}