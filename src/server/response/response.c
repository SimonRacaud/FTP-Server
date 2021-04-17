/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 response.c
*/

#include "response_t.h"

const char *RESPONSE_CODE[NB_RESPONSE + 1] = {
    "120",
    "125",
    "150",
    "200",
    "214",
    "220",
    "221",
    "226",
    "227",
    "230",
    "250",
    "257",
    "500",
    "550",
    "530",
    "425",
    "\0\0\0"
};

const response_t RESPONSES[] = {
    {
        .code = C120,
        .message = "Service ready in nnn minutes."
    },
    {
        .code = C125,
        .message = "Data client open; transfer starting."
    },
    {
        .code = C150,
        .message = "File status okay; about to open data client."
    },
    {
        .code = C200,
        .message = "Success."
    },
    {
        .code = C220,
        .message = "Service ready for new user.",
    },
    {
        .code = C221,
        .message = "Logged out.",
    },
    {
        .code = C226,
        .message = "Closing data client. "
                   "Requested file action successful.",
    },
    {
        .code = C230,
        .message = "User logged in, proceed.",
    },
    {
        .code = C250,
        .message = "Requested file action okay, completed.",
    },
    {
        .code = C500,
        .message = "An error occured.",
    },
    {
        .code = C550,
        .message = "Permission denied.",
    },
    {
        .code = C530,
        .message = "Please login with USER and PASS.",
    },
    {
        .code = C425,
        .message = "Use PORT or PASV first.",
    },
    {
        .code = CNO,
        .message = NULL
    }
};