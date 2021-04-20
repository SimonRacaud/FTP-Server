/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 data_channel_t.h
*/

#ifndef DATA_CHANNEL_T_H
#define DATA_CHANNEL_T_H

#include "socket_t.h"

typedef enum data_channel_mode {
    ACTIVE,
    PASSIVE
} channel_mode_e;

typedef struct active_mode_parameters {
    char ip[INET_ADDRSTRLEN];
    uint port;
} active_args_t;

typedef struct data_channel {
    socket_t sock;
    socket_t passive_server;
    active_args_t args_active;
    channel_mode_e mode;
    bool used;
} data_channel_t;

#endif // DATA_CHANNEL_T_H
