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

typedef struct data_channel {
    socket_t sock;
    channel_mode_e mode;
} data_channel_t;

#endif // DATA_CHANNEL_T_H
