/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 app_destroy.c
*/

#include "app.h"
#include "server.h"

int app_destroy(app_t *app)
{
    if (server_destroy(&app->server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    account_destroy(app);
    return EXIT_SUCCESS;
}