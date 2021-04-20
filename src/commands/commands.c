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
        .description = "<description>",
        .need_auth = false,
        .case_insensitive = true
    },
    {
        .label = "PASS",
        .func = &command_pass,
        .description = "<description>",
        .need_auth = false,
        .case_insensitive = true
    },
    {
        .label = "QUIT",
        .func = &command_quit,
        .description = "<description>",
        .need_auth = false,
        .case_insensitive = false
    },
    {
        .label = "CWD",
        .func = &command_cwd,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "CDUP",
        .func = &command_cdup,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "PWD",
        .func = &command_pwd,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "DELE",
        .func = &command_dele,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "HELP",
        .func = &command_help,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = true
    },
    {
        .label = "NOOP",
        .func = &command_noop,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "PASV",
        .func = &command_pasv,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "PORT",
        .func = &command_port,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "RETR",
        .func = &command_retr,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "STOR",
        .func = &command_stor,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = "LIST",
        .func = &command_list,
        .description = "<description>",
        .need_auth = true,
        .case_insensitive = false
    },
    {
        .label = NULL,
        .func = NULL,
        .description = NULL,
        .need_auth = false,
        .case_insensitive = false
    }
};