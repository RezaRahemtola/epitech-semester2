/*
** EPITECH PROJECT, 2022
** solostumper2
** File description:
** main.c
*/

#include <unistd.h>

void hidenp(char *needle, char *haystack);

static int check_errors(int argc)
{
    if (argc != 3) return (84);
    return (0);
}

int main(int argc, char **argv)
{
    if (check_errors(argc) == 84) {
        write(2, "Usage: ./hidenp needle haystack\n", 32);
        return (84);
    }
    hidenp(argv[1], argv[2]);
    return (0);
}
