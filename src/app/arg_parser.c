/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 arg_parser.c
*/

#include "app.h"

static const char *HELP_TOKEN[] = {"-h", "--help", NULL};

static bool show_help(int argc, char **argv)
{
    for (size_t i = 0; i < (size_t)argc; i++) {
        if (strcmp(argv[i], HELP_TOKEN[0]) == 0
                    || strcmp(argv[i], HELP_TOKEN[1]) == 0) {
            return true;
        }
    }
    return false;
}

static bool is_number(const char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]) == false) {
            return false;
        }
    }
    return true;
}

int arg_parser(int argc, char **argv, args_t *dest)
{
    if (show_help(argc, argv)) {
        exit(usage(EXIT_SUCCESS, argv[0]));
    }
    if (!dest || argc != 3 || is_number(argv[1]) == false) {
        return EXIT_FAILURE;
    }
    dest->port = (uint) strtoul(argv[1], NULL, 10);
    dest->home_path = argv[2];
    return EXIT_SUCCESS;
}