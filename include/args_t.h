/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 args_t.h
*/

#ifndef ARGS_T_H
#define ARGS_T_H

#include <stdlib.h>

// Application arguments

typedef struct app_args {
    char *home_path;
    uint port;
} args_t;

#endif // ARGS_T_H
