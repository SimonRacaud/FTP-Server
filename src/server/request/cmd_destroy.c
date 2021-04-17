/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 cmd_destroy.c
*/

#include "command_t.h"
#include <stdlib.h>

void cmd_destroy(cmd_t *cmd)
{
    free(cmd->label);
    if (cmd->argv) {
        free(cmd->argv);
    }
    free(cmd);
}