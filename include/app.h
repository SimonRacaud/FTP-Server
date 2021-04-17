/*
** EPITECH PROJECT, 2021
** 0_C_BASE_FILES
** File description:
** app
*/

#ifndef APP_H_
#define APP_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#include "app_t.h"
#include "args_t.h"

#ifdef EXIT_FAILURE
    #undef EXIT_FAILURE
#endif
#define EXIT_FAILURE 84

// Core
int arg_parser(int argc, char **argv, args_t *dest);
int signal_init(app_t *app);

int app_init(app_t *app, args_t *args, uint max_client);
int app_loop(app_t *app);
int app_destroy(app_t *app);

int account_init(app_t *app, const char *default_path);
void account_destroy(app_t *app);

int usage(int status, const char *bin);

#endif /* !APP_H_ */
