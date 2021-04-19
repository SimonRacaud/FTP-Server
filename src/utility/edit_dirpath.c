/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 19/04/2021 edit_dirpath.c
*/

#include <stdlib.h>
#include <string.h>

static char *edit_dirpath_absolute(const char *home, const char *new)
{
    char *path;

    path = realpath(new, NULL);
    if (!path)
        return NULL;
    if (strncmp(path, home, strlen(home)) != 0) {
        free(path);
        return NULL;
    }
    return path;
}

static char *edit_dirpath_relative(
    const char *home, const char *prev, const char *new)
{
    size_t len = (strlen(prev) + strlen(new) + 1);
    char *buffer = malloc(sizeof(char) * len);
    char *result = malloc(sizeof(char) * len);

    if (!buffer || !result) {
        return NULL;
    }
    strcpy(buffer, prev);
    strcat(buffer, "/");
    strcat(buffer, new);
    if (realpath(buffer, result) == NULL)
        return NULL;
    free(buffer);
    if (strncmp(result, home, strlen(home)) != 0) {
        free(result);
        return NULL;
    }
    return result;
}

char *edit_dirpath(const char *home, const char *prev, const char *new)
{
    char *result;

    if (!new || !home || !prev)
        return NULL;
    if (new[0] == '/') {
        result = edit_dirpath_absolute(home, new);
    } else {
        result = edit_dirpath_relative(home, prev, new);
    }
    return result;
}