/*
** EPITECH PROJECT, 2022
** solostumper5
** File description:
** rostring
*/

#include <unistd.h>
#include <stdlib.h>

static int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

static char *my_str_allocfill(int nb_char, char c)
{
    char *str = malloc(sizeof(char) * nb_char);

    for (int i = 0; i < nb_char; i++)
        str[i] = c;
    return (str);
}

static int incoming_spaces(char *str)
{
    int count = 0;

    while (str[count] == ' ' || str[count] == '\t')
        count++;
    return (count);
}

void rostring(char *str)
{
    char **str_ptr = &str;
    char *first = my_str_allocfill(my_strlen(str) + 1, '\0');

    (*str_ptr) += incoming_spaces(str);
    while (str[0] != ' ' && str[0] != '\t' && str[0] != '\0') {
        first[my_strlen(first)] = str[0];
        (*str_ptr)++;
    }
    (*str_ptr) += incoming_spaces(str);
    while (str[0] != '\0') {
        while (str[0] != ' ' && str[0] != '\t' && str[0] != '\0') {
            write (1, &str[0], 1);
            (*str_ptr)++;
        }
        (*str_ptr) += incoming_spaces(str);
        write(1, " ", 1);
    }
    write(1, first, my_strlen(first));
    write(1, "\n", 1);
    free(first);
}
