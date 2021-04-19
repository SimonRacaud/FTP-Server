/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 cmd_create.c
*/

#include "server.h"
#include "utility.h"

static ssize_t get_space_idx(const char *command)
{
    for (size_t i = 0; command[i] != '\0'; i++) {
        if (command[i] == ' ') {
            return i;
        }
    }
    return -1;
}

static void parse_command(const char *command, ssize_t space_idx, cmd_t *cmd)
{
    size_t len = strlen(&command[space_idx + 1]);

    cmd->label = strndup(command, space_idx);
    cmd->argv = strndup(&command[space_idx + 1], len - 1);
}

cmd_t *cmd_create(const char *command)
{
    ssize_t space_idx = get_space_idx(command);
    cmd_t *cmd = malloc(sizeof(cmd_t));
    size_t len = strlen(command);

    if (cmd == NULL) {
        return NULL;
    } else if (space_idx == -1) {
        cmd->label = strndup(command, len - 1);
        cmd->argv = NULL;
    } else {
        parse_command(command, space_idx, cmd);
    }
    str_to_upper(cmd->label);
    return cmd;
}