/*
** EPITECH PROJECT, 2022
** solostumper3
** File description:
** main.c
*/

#include <stdlib.h>

void fizzbuzz(int a, int b);

static int check_errors(int argc, char **argv)
{
    if (argc != 3)
        return (84);
    if (atoi(argv[1]) > atoi(argv[2]))
        return (84);
    return (0);
}

int main(int argc, char **argv)
{
    if (check_errors(argc, argv) == 84)
        return (84);
    fizzbuzz(atoi(argv[1]), atoi(argv[2]));
    return (0);
}
