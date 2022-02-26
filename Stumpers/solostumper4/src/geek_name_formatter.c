/*
** EPITECH PROJECT, 2022
** solostumper4
** File description:
** geek_name_formatter.c
*/

#include <unistd.h>

static char check_special(char current, char c)
{
    if (current == 'o' || current == 'O')
        return ('0');
    if (current == 'i' || current == 'I')
        return ('1');
    if (current == 'u' || current == 'U')
        return ('2');
    if (current == 'e' || current == 'E')
        return ('3');
    if (current == 'a' || current == 'A')
        return ('4');
    if (current == 'y' || current == 'Y')
        return ('5');
    return (c);
}

void geek_name_formatter(char *str)
{
    int up = 1;
    char c = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];
        if (up == 1 && str[i] >= 'a' && str[i] <= 'z')
            c = str[i] - 32;
        if (up == -1 && str[i] >= 'A' && str[i] <= 'Z')
            c = str[i] + 32;
        c = check_special(str[i], c);
        up *= -1;
        if (str[i] == ' ' || str[i] == '\t')
            up = 1;
        write(1, &c, 1);
    }
    write(1, "\n", 1);
}
