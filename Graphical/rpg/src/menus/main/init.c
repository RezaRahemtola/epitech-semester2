/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Main menu initialization
*/

#include <stdlib.h>
#include "main_menu.h"
#include "my_string.h"

static void adjust_texts(sfText **texts, sfVector2u *size)
{
    int len = 0;
    int str = 0;
    sfVector2f pos = { 0, 0 };

    for (int i = 0; texts[i] != NULL; i++) {
        len = sfText_getCharacterSize(texts[i]);
        str = my_strlen(sfText_getString(texts[i]));
        pos = sfText_getPosition(texts[i]);
        pos.x = (size->x / 2.25) - (str * len / 4);
        pos.y += size->y / 4;
        sfText_setPosition(texts[i], pos);
    }
}

static bool init_texts(main_menu_t *menu, game_t *game)
{
    sfVector2u win = sfRenderWindow_getSize(game->window);
    sfFont *font = sfFont_createFromFile("assets/main_menu/font.ttf");
    sfText **texts = malloc(sizeof(sfText *) * 5);
    char *info[4] = { "Play", "How to play", "Settings", "Exit" };

    if (font == NULL || texts == NULL) {
        return (false);
    }
    menu->font = font;
    for (int i = 0; i < 4; i++) {
        texts[i] = sfText_create();
        sfText_setString(texts[i], info[i]);
        sfText_setFont(texts[i], font);
        sfText_setCharacterSize(texts[i], win.y / 35);
        sfText_setColor(texts[i], sfWhite);
    }
    texts[4] = NULL;
    menu->texts = texts;
    return (true);
}

static bool init_buttons(main_menu_t *menu, game_t *game)
{
    sfTexture *texture = menu->button_texture;
    sfVector2u win = sfRenderWindow_getSize(game->window);
    sfVector2u tex = sfTexture_getSize(menu->button_texture);
    float gap = tex.y * 1.5;
    sfVector2f pos = { win.x / 2 - tex.x / 6, win.y / 2 - tex.y / 2 };

    menu->buttons = create_button(texture, pos, BUTTON_PLAY);
    sfText_setPosition(menu->texts[0], pos);
    pos.y += gap;
    add_button(&menu->buttons, create_button(texture, pos, BUTTON_TUTORIAL));
    sfText_setPosition(menu->texts[1], pos);
    pos.y += gap;
    add_button(&menu->buttons, create_button(texture, pos, BUTTON_SETTINGS));
    sfText_setPosition(menu->texts[2], pos);
    pos.y += gap;
    add_button(&menu->buttons, create_button(texture, pos, BUTTON_EXIT));
    sfText_setPosition(menu->texts[3], pos);
    adjust_texts(menu->texts, &tex);
    return (menu->buttons != NULL);
}

static bool init_background(main_menu_t *main_menu)
{
    main_menu->bg_sprite = sfSprite_create();
    if (main_menu->bg_sprite == NULL) {
        return (false);
    }
    sfSprite_setTexture(main_menu->bg_sprite, main_menu->bg_texture, sfFalse);
    main_menu->bg_sprite = main_menu->bg_sprite;
    return (true);
}

main_menu_t *init_main_menu(game_t *game)
{
    main_menu_t *main_menu = malloc(sizeof(main_menu_t));
    char *bg_path = "assets/bg.png";
    char *button_path = "assets/main_menu/button.png";

    if (main_menu == NULL || !init_texts(main_menu, game)) {
        return (NULL);
    }
    main_menu->bg_texture = sfTexture_createFromFile(bg_path, NULL);
    main_menu->button_texture = sfTexture_createFromFile(button_path, NULL);
    main_menu->buttons = NULL;
    if (main_menu->bg_texture == NULL || main_menu->button_texture == NULL) {
        return (NULL);
    } else if (!init_background(main_menu) || !init_buttons(main_menu, game)) {
        free_main_menu(main_menu);
        return (NULL);
    }
    return (main_menu);
}
