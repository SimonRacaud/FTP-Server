/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 dchannel_list_remove.c
*/

#include "server.h"

static data_channel_t **realloc_list(
    size_t size, data_channel_t **list, data_channel_t *to_remove)
{
    data_channel_t **res = malloc(sizeof(data_channel_t *) * size);
    size_t idx = 0;

    if (!res)
        return NULL;
    res[size - 1] = NULL;
    for (size_t i = 0; i < size; i++) {
        if (list[i] != to_remove) {
            res[idx++] = list[i];
        } else if (dchannel_destroy(list[i])) {
            return NULL;
        }
    }
    free(list);
    return res;
}

int dchannel_list_remove(data_channel_t ***list_ptr, data_channel_t *to_remove)
{
    size_t size = 0;

    if (*list_ptr == NULL) {
        return EXIT_SUCCESS;
    }
    for (; (*list_ptr)[size] != NULL; size++);
    *list_ptr = realloc_list(size, *list_ptr, to_remove);
    if (*list_ptr == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}