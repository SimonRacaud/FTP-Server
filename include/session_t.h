/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 session_t.h
*/

#ifndef SESSION_T_H
#define SESSION_T_H

#include <stdbool.h>

#include "account_t.h"

typedef struct session {
    char *username;
    account_t *account_ptr;
    bool is_logged;
} session_t;

#endif // SESSION_T_H
