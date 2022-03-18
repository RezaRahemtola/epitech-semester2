/*
** EPITECH PROJECT, 2022
** duo_stumper2
** File description:
** replace.c
*/

#include <string.h>
#include <stdlib.h>
#include "my_strings.h"

char **modify_argv(int argc, char **argv)
{
    char **res = malloc(sizeof(char *) * (argc + 1));

    if (res == NULL)
        return NULL;
    for (int i = 0; argv[i] != NULL; i++) {
        res[i] = my_str_allocfill(sizeof(char) * (strlen(argv[i]) + 1), '\0');
        if (res[i] == NULL)
            return NULL;
        if (strcmp(argv[i], "-p1") == 0)
            strcpy(res[i], "-1");
        if (strcmp(argv[i], "-p2") == 0)
            strcpy(res[i], "-2");
        if (strcmp(argv[i], "-p1") != 0 && strcmp(argv[i], "-p2") != 0)
            strcpy(res[i], argv[i]);
    }
    res[argc] = NULL;
    return res;
}
