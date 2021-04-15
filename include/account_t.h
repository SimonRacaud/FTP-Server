/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 account_t.h
*/

#ifndef ACCOUNT_T_H
#define ACCOUNT_T_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct account {
    char *username;
    char *password;
    char *home_path;
} account_t;

#endif // ACCOUNT_T_H
