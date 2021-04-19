/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 command_t.h
*/

#ifndef COMMAND_T_H
#define COMMAND_T_H

#include <stdbool.h>

#include "response_t.h"
#include "app_t.h"
#include "server_t.h"

// Parsed command

typedef struct cmd {
    char *label;
    char *argv;
} cmd_t;

// Available command description

typedef int (* cmd_func)(app_t *, connection_t *, cmd_t *);

typedef struct command {
    char *label;
    cmd_func func;
    bool need_auth;
    bool case_insensitive;
} command_t;

#endif // COMMAND_T_H
