/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 command_user.c
*/

#include "app.h"
#include "server.h"

static int pre_process(connection_t *client, const char *username)
{
    if (client->session.is_logged && IS_GUEST(client->session)) {
        if (send_response(
                &client->sock, C530, "Can't change from guest user."))
            return EXIT_FAILURE;
        return EXIT_QUIT;
    }
    if (!username || username[0] == '\0') {
        if (send_response(&client->sock, C530, "Permission denied."))
            return EXIT_FAILURE;
        return EXIT_QUIT;
    }
    if (client->session.username != NULL) {
        free(client->session.username);
    }
    return EXIT_SUCCESS;
}

int command_user(
    __attribute__((unused)) app_t *app, connection_t *client, cmd_t *request)
{
    char *username = request->argv;
    int status = pre_process(client, username);

    if (status == EXIT_FAILURE)
        return EXIT_FAILURE;
    else if (status == EXIT_QUIT)
        return EXIT_SUCCESS;
    if (client->session.is_logged) {
        return send_response(
            &client->sock, C530, "Can't change from guest user.");
    }
    client->session.username = strdup(username);
    return send_response(&client->sock, C331, "Please specify the password.");
}