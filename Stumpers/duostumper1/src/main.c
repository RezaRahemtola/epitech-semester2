/*
** EPITECH PROJECT, 2022
** duostumper1
** File description:
** main.c
*/

#include "my.h"
#include "fractals.h"

int main(int argc, char **argv)
{
    if (!error_handling(argc, argv))
        return (84);
    if (edge_cases(argv[1], argv[2], argv[3]))
        return (0);
    fractals(my_getnbr(argv[1]), argv[2], argv[3]);
    return (0);
}
