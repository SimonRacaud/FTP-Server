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

#include "command_t.h"
#include "connection_t.h"
#include "data_channel_t.h"
#include "server_t.h"
#define READ_SIZE 42
#define LOGOUT_CMD "QUIT"

#define IS_LOGOUT(cmd) !strcmp(cmd->label, "QUIT")

int server_create(server_t *server, uint port, uint max_client);
int server_destroy(server_t *server);

int server_client_requests_process(app_t *app, server_t *server);
int server_client_manager(app_t *app, connection_t *client);
int server_connect_client(server_t *server);
int server_dchannel_requests_process(select_t *select, connection_t **clients);

// RESPONSE
int send_response(socket_t *sock, code_e code, const char *message);
int send_raw_message(socket_t *sock, const char *message);

// COMMAND
cmd_t *cmd_create(const char *command);
void cmd_destroy(cmd_t *cmd);
cmd_t *get_request(connection_t *client, bool *is_error);
bool have_available_command_in_buffer(connection_t *client);
int server_execute_cmd(app_t *app, connection_t *client, cmd_t *request);

//  CONNECTION
connection_t *connection_create(int server_fd);
int connection_destroy(connection_t *conn);
int connection_list_push(connection_t *node, connection_t ***clients_ptr);
int connection_list_remove(server_t *server, connection_t *to_remove);
int connection_list_destroy(connection_t **list);

//  DATA CHANNEL
data_channel_t *dchannel_create(
    channel_mode_e mode, uint port, const char *ip);
int dchannel_destroy(data_channel_t *dchannel);
int dchannel_list_add(data_channel_t *node, data_channel_t ***list_ptr);
int dchannel_list_destroy(data_channel_t **list);
int dchannel_list_remove(
    data_channel_t ***list_ptr, data_channel_t *to_remove);
pid_t dchannel_prepare(connection_t *client, data_channel_t *channel);
active_args_t get_active_channel_args(socket_t *client);
int dchannel_list_clean(data_channel_t ***list_ptr);
data_channel_t *dchannel_get_free_channel(data_channel_t **list);
int load_active_dchannel_args(active_args_t *dest, socket_t *client);

#endif // SERVER_H
