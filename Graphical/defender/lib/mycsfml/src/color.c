/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Color functions'
*/

#include <stdlib.h>
#include "mycsfml_color.h"

sfColor get_rand_color(void)
{
    sfColor new_color = {rand() % 255, rand() % 255, rand() % 255, 255};

    return (new_color);
}
