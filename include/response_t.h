/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 response_t.h
*/

#ifndef RESPONSE_T_H
#define RESPONSE_T_H

#include <stdbool.h>
#include <stddef.h>

typedef enum response_code {
    C120 = 0,
    C125 = 1,
    C150 = 2,
    C200 = 3,
    C214 = 4,
    C220 = 5,
    C221 = 6,
    C226 = 7,
    C227 = 8,
    C230 = 9,
    C250 = 10,
    C257 = 11,
    C500 = 12,
    C550 = 13,
    C530 = 14,
    C425 = 15,
    C331 = 16,
    C503 = 17,
    C426 = 18,
    CNO
} code_e;

typedef struct response {
    code_e code;
    const char *message;
} response_t;

#endif // RESPONSE_T_H
