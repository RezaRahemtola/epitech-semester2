/*
** EPITECH PROJECT, 2022
** SoloStumper1
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "countwords.h"

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("\n");
        return (0);
    } else if (argc != 2) {
        return (84);
    }
    countwords(argv[1]);
    return (0);
}
