/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 commands.c
*/

#include "command.h"

const command_t COMMANDS[] = {
    {
        .label = "USER",
        .func = &command_user,
        .need_auth = false
    },
    {
        .label = "PASS",
        .func = &command_pass,
        .need_auth = false
    },
    {
        .label = "QUIT",
        .func = &command_quit,
        .need_auth = false
    },
    {
        .label = "CWD",
        .func = NULL,
        .need_auth = true
    },
    {
        .label = "CDUP",
        .func = NULL,
        .need_auth = true
    },
    {
        .label = "PWD",
        .func = NULL,
        .need_auth = true
    },
    {
        .label = "DELE",
        .func = NULL,
        .need_auth = true
    },
    {
        .label = "HELP",
        .func = &command_help,
        .need_auth = true
    },
    {
        .label = "NOOP",
        .func = &command_noop,
        .need_auth = true
    },
    {
        .label = "PASV",
        .func = NULL,
        .need_auth = true
    },
    {
        .label = "PORT",
        .func = NULL,
        .need_auth = true
    },
    {
        .label = "RETR",
        .func = NULL,
        .need_auth = true
    },
    {
        .label = "STOR",
        .func = NULL,
        .need_auth = true
    },
    {
        .label = "LIST",
        .func = NULL,
        .need_auth = true
    },
    {
        .label = NULL,
        .func = NULL,
        .need_auth = false
    }
};