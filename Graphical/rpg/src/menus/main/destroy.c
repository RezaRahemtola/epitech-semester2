/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Main menu destruction
*/

#include <stdlib.h>
#include "main_menu.h"

void free_main_menu(main_menu_t *main_menu)
{
    if (main_menu == NULL) {
        return;
    }
    sfTexture_destroy(main_menu->bg_texture);
    sfTexture_destroy(main_menu->button_texture);
    sfSprite_destroy(main_menu->bg_sprite);
    sfFont_destroy(main_menu->font);
    destroy_buttons(main_menu->buttons, false);
    for (int i = 0; i < 4; i++) {
        sfText_destroy(main_menu->texts[i]);
    }
    free(main_menu->texts);
    free(main_menu);
}
