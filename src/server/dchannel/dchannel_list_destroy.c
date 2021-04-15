/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 dchannel_list_destoy.c
*/

#include "server.h"

int dchannel_list_destroy(data_channel_t **list)
{
    for (size_t i = 0; list[i] != NULL; i++) {
        if (dchannel_destroy(list[i]))
            return EXIT_FAILURE;
    }
    free(list);
    return EXIT_SUCCESS;
}