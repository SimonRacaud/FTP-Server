/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 usage.c
*/

#include "app.h"

int usage(int status, const char *bin)
{
    printf("USAGE: %s port path\n", bin);
    printf("\tport\tis the port number on which the server socket listens\n");
    printf("\tpath\tis the path to the home directory for the Anonymous "
           "user\n");
    return status;
}