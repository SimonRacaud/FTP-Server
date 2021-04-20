/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 dchannel_prepare.c
*/

#include "server.h"
#include "socket.h"

static int child_job(data_channel_t *chan)
{
    active_args_t *args = &chan->args_active;

    if (chan->mode == ACTIVE) {
        if (!args)
            return EXIT_FAILURE;
        if (socket_client_connect(&chan->sock, args->port, args->ip))
            return EXIT_FAILURE;
    } else if (chan->mode == PASSIVE && chan->sock.fd == -1) {
        if (socket_server_connect(&chan->sock, chan->passive_server.fd))
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int parent_job(connection_t *client, data_channel_t *chan)
{
    if (send_response(
            &client->sock, C150, "ok, about to open data connection."))
        return EXIT_FAILURE;
    if (dchannel_list_remove(&client->channel_list, chan) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

pid_t dchannel_prepare(connection_t *client, data_channel_t *channel)
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (child_job(channel) == EXIT_FAILURE)
            return -1;
    } else {
        if (parent_job(client, channel) == EXIT_FAILURE)
            return -1;
    }
    return pid;
}