/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 signal_init.c
*/

#include "app.h"
#include <signal.h>

static void exit_action(bool *ptr)
{
    static bool *loop_ptr = NULL;

    if (ptr != NULL) {
        loop_ptr = ptr;
    } else if (loop_ptr != NULL) {
        *loop_ptr = false;
    }
}

static void signal_handler(__attribute__((unused))int code)
{
    exit_action(NULL);
}

int signal_init(app_t *app)
{
    exit_action(&app->loop);
    if (signal(SIGINT, &signal_handler) == SIG_ERR) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}