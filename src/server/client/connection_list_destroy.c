/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 connection_list_destroy.c
*/

#include "server.h"

int connection_list_destroy(connection_t **list)
{
    for (size_t i = 0; list && list[i] != NULL; i++) {
        if (connection_destroy(list[i]))
            return EXIT_FAILURE;
    }
    if (list != NULL) {
        free(list);
    }
    return EXIT_SUCCESS;
}