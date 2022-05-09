/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Stats menu
*/

#include "hud.h"

static void scale_button(buttons_t *button)
{
    sfVector2u size = sfTexture_getSize(button->texture);
    sfVector2f scale = { 0, 0 };

    scale.x = 65.0f / (float) size.x * 3;
    scale.y = 65.0f / (float) size.y;
    sfSprite_setScale(button->sprite, scale);
}

static bool init_stats_buttons(hud_t *hud)
{
    char *assets[4] = { "assets/hud/attack.png", "assets/hud/defense.png", \
        "assets/hud/speed.png", "assets/hud/health.png" };
    sfVector2f pos[4] = { { 30, 980 }, { 120, 980 }, { 210, 980 }, \
        { 300, 980 } };
    sfTexture *texture = NULL;
    buttons_t *button = NULL;

    for (int i = 0; i < 4; i++) {
        texture = sfTexture_createFromFile(assets[i], NULL);
        if (texture == NULL) {
            return (false);
        }
        button = create_button(texture, pos[i], i);
        if (button == NULL) {
            return (false);
        }
        scale_button(button);
        add_button(&hud->stats_buttons, button);
    }
    return (true);
}

static void init_points_text(hud_t *hud)
{
    sfVector2f pos = { 100, 890 };

    sfText_setFont(hud->points_text, hud->font);
    sfText_setColor(hud->points_text, sfWhite);
    sfText_setCharacterSize(hud->points_text, 40);
    sfText_setPosition(hud->points_text, pos);
}

static bool init_points(hud_t *hud)
{
    sfVector2u size;
    sfVector2f scale;
    sfVector2f pos = { 40, 890 };
    sfTexture *txt = sfTexture_createFromFile("assets/hud/points.png", NULL);

    hud->points_texture = txt;
    if (hud->points_texture == NULL) {
        return (false);
    }
    hud->points_sprite = sfSprite_create();
    hud->points_text = sfText_create();
    size = sfTexture_getSize(hud->points_texture);
    scale.x = 50.0f / (float) size.x;
    scale.y = 50.0f / (float) size.y;
    sfSprite_setTexture(hud->points_sprite, hud->points_texture, sfFalse);
    sfSprite_setScale(hud->points_sprite, scale);
    sfSprite_setPosition(hud->points_sprite, pos);
    init_points_text(hud);
    return (true);
}

bool init_stats(hud_t *hud)
{
    hud->stats_buttons = NULL;
    hud->stats_texts = malloc(sizeof(sfText *) * 4);
    if (hud->stats_texts == NULL) {
        return (false);
    }
    for (int i = 0; i < 4; i++) {
        hud->stats_texts[i] = sfText_create();
        sfText_setFont(hud->stats_texts[i], hud->font);
        sfText_setColor(hud->stats_texts[i], sfWhite);
        sfText_setCharacterSize(hud->stats_texts[i], 20);
    }
    return (init_stats_buttons(hud) && init_points(hud));
}
