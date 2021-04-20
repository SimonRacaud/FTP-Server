/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 20/04/2021 command_pasv.c
*/

#include <arpa/inet.h>
#include "app.h"
#include "server.h"

static const size_t RESPONSE_MAX_LEN = 50;

static int send_answer(socket_t *chan_sock, connection_t *client)
{
    char ip[INET_ADDRSTRLEN];
    int d_ip[4];
    char buffer[RESPONSE_MAX_LEN];
    int dport[2];
    uint16_t port;
    socklen_t len = sizeof(struct sockaddr);

    getsockname(chan_sock->fd, (struct sockaddr *) &chan_sock->conf, &len);
    inet_ntop(AF_INET, &(chan_sock->conf.sin_addr), ip, INET_ADDRSTRLEN);
    port = htons(chan_sock->conf.sin_port);
    dport[0] = port / 256;
    dport[1] = port % 256;
    if (sscanf(ip, "%d.%d.%d.%d", &d_ip[0], &d_ip[1], &d_ip[2], &d_ip[3]) != 4)
        return EXIT_FAILURE;
    sprintf(buffer, "Entering Passive Mode (%d,%d,%d,%d,%d,%d).\n", d_ip[0],
        d_ip[1], d_ip[2], d_ip[3], dport[0], dport[1]);
    return send_response(&client->sock, C227, buffer);
}

int command_pasv(__attribute__((unused)) app_t *app, connection_t *client,
    __attribute__((unused)) cmd_t *request)
{
    data_channel_t *node;

    dchannel_list_clean(&client->channel_list);
    node = dchannel_create(PASSIVE, 0, NULL);
    if (!node) {
        return send_response(&client->sock, C500, "An error occurred.");
    }
    if (dchannel_list_add(node, &client->channel_list) == EXIT_FAILURE) {
        return send_response(&client->sock, C500, "An error occurred.");
    }
    return send_answer(&node->passive_server, client);
}