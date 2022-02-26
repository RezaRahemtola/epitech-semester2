/*
** EPITECH PROJECT, 2022
** solostumper4
** File description:
** main.c
*/

void geek_name_formatter(char *str);

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    geek_name_formatter(argv[1]);
    return (0);
}
