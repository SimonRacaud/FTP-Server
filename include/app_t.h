/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 app_t.h
*/

#ifndef APP_T_H
#define APP_T_H

#include "account_t.h"
#include "server_t.h"

typedef struct application {
    account_t *account_list;
    server_t server;
} app_t;

#endif // APP_T_H
