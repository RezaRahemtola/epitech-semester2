/*
** EPITECH PROJECT, 2022
** solostumper5
** File description:
** main.c
*/

#include <unistd.h>

void rostring(char *str);

int main(int argc, char **argv)
{
    if (argc != 2) {
        write(1, "\n", 1);
        return (0);
    }
    rostring(argv[1]);
    return (0);
}
