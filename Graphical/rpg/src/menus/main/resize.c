/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Resizing main menu
*/

#include "rpg.h"

void resize_main_menu(main_menu_t *menu, sfRenderWindow *window)
{
    scale_background(window, menu->bg_sprite);
}
