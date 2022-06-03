/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** printing functions
*/

#include <unistd.h>
#include "my_math.h"
#include "my_string.h"
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int size = my_strlen(str);

    write(1, str, size);
}
