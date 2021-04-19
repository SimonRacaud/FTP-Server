/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 account.c
*/

#include "account_t.h"
#include "app_t.h"
#include <string.h>

static const account_t ACCOUNT[] = {
    {
        .username = "ANONYMOUS",
        .password = "",
        .home_path = NULL
    },
    {
        .username = "X",
        .password = "",
        .home_path = NULL
    },
    {
        .username = NULL,
        .password = NULL,
        .home_path = NULL
    }
};

int account_init(app_t *app, const char *default_path)
{
    size_t nb_account = 0;

    for (; ACCOUNT[nb_account].username != NULL; nb_account++);
    app->account_list = malloc(sizeof(account_t *) * (nb_account + 1));
    if (!app->account_list)
        return EXIT_FAILURE;
    app->account_list[nb_account] = NULL;
    for (size_t i = 0; i < nb_account; i++) {
        app->account_list[i] = malloc(sizeof(account_t));
        if (!app->account_list[i])
            return EXIT_FAILURE;
        app->account_list[i]->username = ACCOUNT[i].username;
        app->account_list[i]->password = ACCOUNT[i].password;
        app->account_list[i]->home_path = strdup(default_path);
    }
    return EXIT_SUCCESS;
}

void account_destroy(app_t *app)
{
    for (size_t i = 0; app->account_list[i]; i++) {
        free(app->account_list[i]->home_path);
        free(app->account_list[i]);
    }
    free(app->account_list);
}