/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 send_response.c
*/

#include "server.h"
#include "socket.h"

extern const response_t RESPONSES[];
extern const char *RESPONSE_CODE[];
const size_t CODE_LENGHT = 3;

static ssize_t get_message_idx(code_e code)
{
    for (size_t i = 0; RESPONSES[i].code != CNO; i++) {
        if (RESPONSES[i].code == code) {
            return (ssize_t) i;
        }
    }
    return -1;
}

static int write_message(socket_t *sock, code_e code, const char *message)
{
    char *buff = malloc(sizeof(char) * CODE_LENGHT + 3 + strlen(message));

    if (!buff)
        return EXIT_FAILURE;
    if (sprintf(buff, "%s %s\n", RESPONSE_CODE[code], message) < 0)
        return EXIT_FAILURE;
    if (socket_send(sock, buff) == EXIT_FAILURE) {
        free(buff);
        return EXIT_FAILURE;
    }
    free(buff);
    return EXIT_SUCCESS;
}

int send_response(socket_t *sock, code_e code, const char *message)
{
    ssize_t idx;

    if (!message) {
        idx = get_message_idx(code);
        if (idx != -1) {
            return write_message(sock, code, RESPONSES[idx].message);
        }
    } else {
        return write_message(sock, code, message);
    }
    return EXIT_SUCCESS;
}