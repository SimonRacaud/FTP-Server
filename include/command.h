/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 command.h
*/

#ifndef COMMAND_H
#define COMMAND_H

#include "server.h"
#include "app_t.h"
#include "command_t.h"

int command_quit(app_t *app, connection_t *client, cmd_t *request);
int command_user(app_t *app, connection_t *client, cmd_t *request);
int command_pass(app_t *app, connection_t *client, cmd_t *request);

int command_noop(app_t *app, connection_t *client, cmd_t *request);
int command_help(app_t *app, connection_t *client, cmd_t *request);

int command_cdup(app_t *app, connection_t *client, cmd_t *request);
int command_cwd(app_t *app, connection_t *client, cmd_t *request);
int command_pwd(app_t *app, connection_t *client, cmd_t *request);

int command_dele(app_t *app, connection_t *client, cmd_t *request);

int command_pasv(app_t *app, connection_t *client, cmd_t *request);
int command_port(app_t *app, connection_t *client, cmd_t *request);
int command_list(app_t *app, connection_t *client, cmd_t *request);
//int command_retr(app_t *app, connection_t *client, cmd_t *request);
//int command_stor(app_t *app, connection_t *client, cmd_t *request);

#endif // COMMAND_H
