/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 20/04/2021 command_port.c
*/

#include "app.h"
#include "server.h"
#include "utility.h"

static const int NB_PARSED_NUMBERS = 6;
static const size_t IP_SIZE = 4;

static char *parse_ip(int *ip)
{
    char *result = NULL;
    char buff[4];

    for (size_t i = 0; i < IP_SIZE; i++) {
        if (i > 0) {
            result = strconcat(result, ".");
        }
        if (ip[i] > 999 || ip[i] < 0) {
            return NULL;
        }
        sprintf(buff, "%d", ip[i]);
        result = strconcat(result, buff);
        if (!result)
            return NULL;
    }
    return result;
}

static int parse_args(active_args_t *dest, char *input)
{
    int ip[IP_SIZE];
    int port[2];
    int status;
    char *parsed_ip;

    status = sscanf(input, "(%d,%d,%d,%d,%d,%d)", &ip[0], &ip[1], &ip[2],
        &ip[3], &port[0], &port[1]);
    if (status != NB_PARSED_NUMBERS)
        return EXIT_FAILURE;
    dest->port = port[0] * 256 + port[1];
    parsed_ip = parse_ip(ip);
    if (dest->ip == NULL) {
        return EXIT_FAILURE;
    }
    if (strlen(parsed_ip) <= INET_ADDRSTRLEN)
        strcpy(dest->ip, parsed_ip);
    else
        return EXIT_FAILURE;
    free(parsed_ip);
    return EXIT_SUCCESS;
}

int command_port(
    __attribute__((unused)) app_t *app, connection_t *client, cmd_t *request)
{
    active_args_t args;
    data_channel_t *node;

    if (!request->argv)
        return send_response(&client->sock, C500, "Missing parameters.");
    dchannel_list_clean(&client->channel_list);
    if (parse_args(&args, request->argv))
        return send_response(&client->sock, C500, "Bad parameters.");
    node = dchannel_create(PASSIVE, args.port, args.ip);
    if (!node) {
        return send_response(&client->sock, C500, "An error occurred.");
    }
    if (dchannel_list_add(node, &client->channel_list) == EXIT_FAILURE) {
        return send_response(&client->sock, C500, "An error occurred.");
    }
    if (send_response(&client->sock, C200, "Passive channel ready."))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}