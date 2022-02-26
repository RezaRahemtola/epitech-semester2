/*
** EPITECH PROJECT, 2022
** solostumper2
** File description:
** hidenp.c
*/

#include <unistd.h>

void hidenp(char *needle, char *haystack)
{
    int i = 0;

    for (int j = 0; needle[i] != '\0' && haystack[j] != '\0'; j++) {
        if (needle[i] == haystack[j])
            i++;
    }
    if (needle[i] == '\0')
        write(1, "1\n", 2);
    else
        write(1, "0\n", 2);
}
