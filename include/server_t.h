/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 server_t.h
*/

#ifndef SERVER_T_H
#define SERVER_T_H

#include <stdlib.h>
#include <stdbool.h>
#include <sys/select.h>

#include "socket_t.h"
#include "connection_t.h"

typedef struct server_select {
    fd_set write_fds;
    fd_set read_fds;
    int status;
} select_t;

typedef struct server {
    socket_t sock;
    uint max_client;
    connection_t *clients;
    select_t select;
} server_t;

#endif // SERVER_T_H
