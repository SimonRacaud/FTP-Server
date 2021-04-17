/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 app_init.c
*/

#include "app.h"
#include "server.h"

int app_init(app_t *app, args_t *args, uint max_client)
{
    if (account_init(app, args->home_path))
        return EXIT_FAILURE;
    if (server_create(&app->server, args->port, max_client))
        return EXIT_FAILURE;
    app->loop = true;
    return EXIT_SUCCESS;
}