/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 server.h
*/

#ifndef SERVER_H
#define SERVER_H

#ifdef EXIT_FAILURE
#undef EXIT_FAILURE
#endif
#define EXIT_FAILURE 84

#include <stdio.h>
#include <string.h>

#include "server_t.h"
#include "connection_t.h"
#include "data_channel_t.h"
#include "command_t.h"

int server_create(server_t *server, uint port, uint max_client);
int server_destroy(server_t *server);

int server_client_requests_process(app_t *app, server_t *server);
int server_client_manager(app_t *app, connection_t *client);
int server_connect_client(server_t *server);
int server_dchannel_requests_process(select_t *select, connection_t **clients);

// COMMAND
cmd_t *cmd_create(const char *command);
void cmd_destroy(cmd_t *cmd);
cmd_t *get_request(connection_t *client, bool *is_error);
int server_execute_cmd(app_t *app, connection_t *client, cmd_t *request);

//  CONNECTION
connection_t *connection_create(int server_fd);
int connection_destroy(connection_t *conn);
int connection_list_push(connection_t *node, connection_t ***clients_ptr);
int connection_list_remove(server_t *server, connection_t *to_remove);
int connection_list_destroy(connection_t **list);

//  DATA CHANNEL
data_channel_t *dchannel_create(channel_mode_e mode);
int dchannel_destroy(data_channel_t *dchannel);
int dchannel_list_add(data_channel_t *node, connection_t *client);
int dchannel_list_destroy(data_channel_t **list);
int dchannel_list_remove(connection_t *client, data_channel_t *to_remove);

#endif // SERVER_H
