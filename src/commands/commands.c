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
        .need_auth = false,
        .case_insensitive = true
    },
    {
        .label = "PASS",
        .func = &command_pass,
        .need_auth = false,
        .case_insensitive = true
    },
    {
        .label = "QUIT",
        .func = &command_quit,
        .need_auth = false,
        .case_insensitive = false
    },
    {
        .label = "CWD",
        .func = &command_cwd,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "CDUP",
        .func = &command_cdup,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "PWD",
        .func = &command_pwd,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "DELE",
        .func = NULL,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "HELP",
        .func = &command_help,
        .need_auth = true,
        .case_insensitive = true
    },
    {
        .label = "NOOP",
        .func = &command_noop,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "PASV",
        .func = NULL,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "PORT",
        .func = NULL,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "RETR",
        .func = NULL,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "STOR",
        .func = NULL,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "LIST",
        .func = NULL,
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = NULL,
        .func = NULL,
        .need_auth = false,
        .case_insensitive = false
    }
};