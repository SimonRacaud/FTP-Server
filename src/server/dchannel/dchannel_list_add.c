/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 dchannel_list_add.c
*/

#include "server.h"

static data_channel_t **add_new_node(
    data_channel_t **list, data_channel_t *node)
{
    size_t size = 0;
    data_channel_t **new_list;

    while (list[size] != NULL)
        size++;
    new_list = malloc(sizeof(data_channel_t *) * (size + 2));
    if (!new_list)
        return NULL;
    for (size_t i = 0; i < size; i++)
        new_list[i] = list[i];
    new_list[size] = node;
    new_list[size + 1] = NULL;
    free(list);
    return new_list;
}

int dchannel_list_add(data_channel_t *node, data_channel_t ***list_ptr)
{
    data_channel_t **list = *list_ptr;

    if (list != NULL) {
        *list_ptr = add_new_node(list, node);
        if (*list_ptr == NULL)
            return EXIT_FAILURE;
    } else {
        *list_ptr = calloc(1, sizeof(data_channel_t *) * 2);
        (*list_ptr)[1] = NULL;
        if (!(*list_ptr))
            return EXIT_FAILURE;
        (*list_ptr)[0] = node;
    }
    return EXIT_SUCCESS;
}