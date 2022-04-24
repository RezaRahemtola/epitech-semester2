/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Main
*/

#include "parsing.h"

int main(int argc, char **argv)
{
    lemin_t *result = parsing();

    if (is_parsing_incomplete(result)) {
        destroy_lemin(result);
        return (84);
    }
    lemin(argc, argv);
    destroy_lemin(result);
    return (0);
}
