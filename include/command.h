/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 command.h
*/

#ifndef COMMAND_H
#define COMMAND_H

#include "command_t.h"
#include "server.h"
#include "app_t.h"

int command_quit(app_t *app, connection_t *client, cmd_t *request);
int command_user(app_t *app, connection_t *client, cmd_t *request);
int command_pass(app_t *app, connection_t *client, cmd_t *request);

int command_noop(app_t *app, connection_t *client, cmd_t *request);
int command_help(app_t *app, connection_t *client, cmd_t *request);

#endif // COMMAND_H
