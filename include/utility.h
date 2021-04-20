/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 utility.h
*/

#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char *edit_dirpath(const char *home, const char *prev, const char *new);
void str_to_upper(char *str);
ssize_t find_newline(const char *str);
bool is_empty(const char *str);
char *strconcat(char *a, const char *b);

#endif // UTILITY_H
