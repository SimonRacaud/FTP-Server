/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 command_pass.cpp.c
*/

#include "app.h"
#include "server.h"
#include "utility.h"

static account_t *find_account(
    account_t **list, const char *username, const char *password)
{
    for (size_t i = 0; list && list[i] != NULL; i++) {
        if (!strcmp(username, list[i]->username)
            && (!strcmp(list[i]->password, "")
                || !strcmp(list[i]->password, password))) {
            return list[i];
        }
    }
    return NULL;
}

static int proceed_request(connection_t *client)
{
    if (!client->session.account_ptr) {
        if (send_response(&client->sock, C530, "Login incorrect."))
            return EXIT_FAILURE;
    } else {
        if (send_response(&client->sock, C230, "Login successful."))
            return EXIT_FAILURE;
        client->session.is_logged = true;
        free(client->workdir);
        client->workdir = strdup(client->session.account_ptr->home_path);
        if (!client->workdir)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int pre_process(connection_t *client)
{
    if (client->session.is_logged && IS_GUEST(client->session)) {
        if (send_response(&client->sock, C230, "Already logged in."))
            return EXIT_FAILURE;
        return EXIT_QUIT;
    }
    if (client->session.username == NULL) {
        if (send_response(&client->sock, C503, "Login with USER first."))
            return EXIT_FAILURE;
        return EXIT_QUIT;
    }
    return EXIT_SUCCESS;
}

int command_pass(app_t *app, connection_t *client, cmd_t *request)
{
    char *password = request->argv;
    int status = pre_process(client);

    if (status == EXIT_FAILURE)
        return EXIT_FAILURE;
    else if (status == EXIT_QUIT)
        return EXIT_SUCCESS;
    client->session.account_ptr =
        find_account(app->account_list, client->session.username, password);
    if (client->session.username != NULL) {
        free(client->session.username);
        client->session.username = NULL;
    }
    if (proceed_request(client) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}