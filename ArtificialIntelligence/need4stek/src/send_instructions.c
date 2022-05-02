/*
** EPITECH PROJECT, 2022
** n4s
** File description:
** Functions to send instructions
*/

#include <stdlib.h>
#include <stdio.h>
#include "ai.h"

void change_speed(float speed)
{
    char *tmp = NULL;
    size_t read = 0;

    dprintf(STDOUT, "CAR_FORWARD:%f\n", speed);
    getline(&tmp, &read, stdin);
    free(tmp);
}

void change_direction(float wheels)
{
    char *tmp = NULL;
    size_t read = 0;

    dprintf(STDOUT, "WHEELS_DIR:%f\n", wheels);
    getline(&tmp, &read, stdin);
    free(tmp);
}
