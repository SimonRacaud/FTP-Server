/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "app.h"

int main(int argc, char **argv)
{
    args_t parsed_args;
    app_t app;
    const uint max_client = 100;

    if (arg_parser(argc, argv, &parsed_args) == EXIT_FAILURE) {
        fprintf(stderr, "%s: Invalid parameters\n\n", argv[0]);
        return usage(EXIT_FAILURE, argv[0]);
    }
    if (app_init(&app, &parsed_args, max_client) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (signal_init(&app) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (app_loop(&app) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (app_destroy(&app) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
