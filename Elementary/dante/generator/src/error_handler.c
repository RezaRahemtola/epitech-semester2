/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Error handling module
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "generator.h"

bool check_args(int argc, char **argv)
{
    if (argc > 2 && argc < 5) {
        if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0) {
            fprintf(stderr, "Error: Invalid size arguments.\n");
            return false;
        }
        if (argc == 4 && strcmp(argv[3], "perfect") != 0) {
            fprintf(stderr, "Error: Invalid third argument.\n");
            return false;
        }
    } else {
        fprintf(stderr, "Error: Invalid number of arguments.\n");
        return false;
    }
    return true;
}
