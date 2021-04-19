/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 connection_t.h
*/

#ifndef CONNECTION_T_H
#define CONNECTION_T_H

#include "socket_t.h"
#include "session_t.h"
#include "data_channel_t.h"

#define CLIENT_HOME(client) (client->session.account_ptr) ? \
                                client->session.account_ptr->home_path : NULL

typedef struct connection {
    socket_t sock;
    session_t session;
    data_channel_t **channel_list;
    char *workdir;
} connection_t;

#endif // CONNECTION_T_H
