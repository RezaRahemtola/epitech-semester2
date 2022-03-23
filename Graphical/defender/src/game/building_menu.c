/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Functions for the building menu
*/

#include "defender.h"

static const sfTexture *get_clicked_build(sfEvent *event, building_t *building,
info_t *info)
{
    sfTexture *texture = NULL;

    if (is_click_on_sprite(event, building->buy_fire))
        texture = info->tower_types[SINGLE_DMG]->texture;
    if (is_click_on_sprite(event, building->buy_ice))
        texture = info->tower_types[SLOW]->texture;
    if (is_click_on_sprite(event, building->buy_poison))
        texture = info->tower_types[ZONE_DMG]->texture;
    if (is_click_on_sprite(event, building->buy_mid))
        texture = info->tower_types[MID]->texture;
    return (texture);
}

void check_building_menu_click(sfEvent *event, building_t *building,
info_t *info, game_t *game)
{
    const sfTexture *old_textu = sfSprite_getTexture(building->dragged_sprite);
    const sfTexture *dragged = NULL;
    bool old_dragged = building->is_dragged;
    sfVector2f mouse = {event->mouseButton.x, event->mouseButton.y};

    if (event->mouseButton.button != sfMouseLeft)
        return;
    building->is_dragged = false;
    if (event->type == sfEvtMouseButtonPressed) {
        dragged = get_clicked_build(event, building, info);
        if (dragged != NULL) {
            building->is_dragged = true;
            sfSound_play(building->button_sound->sound);
            sfSprite_setTexture(building->dragged_sprite, dragged, sfFalse);
        }
    }
    if (event->type == sfEvtMouseButtonReleased && old_dragged)
        create_tower(&mouse, old_textu, game, info);
}

static void disp_stats(building_t *building, sfRenderWindow *win, game_t *game)
{
    char *g_txt = game->gold > 0 ? my_nb_to_str(game->gold) : my_strdup("0");
    char *kills_txt = my_nb_to_str(game->kills);
    char *health_txt = game->hp > 0 ? my_nb_to_str(game->hp) : my_strdup("0");
    text_t *kills = text_create(kills_txt, "assets/score.otf", sfBlack, 45);
    text_t *gold = text_create(g_txt, "assets/score.otf", sfBlack, 45);
    text_t *health = text_create(health_txt, "assets/score.otf", sfBlack, 45);

    sfText_setPosition(gold->text, (sfVector2f){1600, 0});
    sfText_setPosition(kills->text, (sfVector2f){1450, 0});
    sfText_setPosition(health->text, (sfVector2f){1260, 0});
    sfRenderWindow_drawText(win, gold->text, NULL);
    sfRenderWindow_drawText(win, kills->text, NULL);
    sfRenderWindow_drawText(win, health->text, NULL);
    sfRenderWindow_drawSprite(win, building->gold, NULL);
    sfRenderWindow_drawSprite(win, building->kill, NULL);
    sfRenderWindow_drawSprite(win, building->health, NULL);
    csfml_destroyer("TTT", gold, kills, health);
    free(g_txt);
    free(kills_txt);
    free(health_txt);
}

void display_building(building_t *building, sfRenderWindow *win, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfIntRect rect = sfSprite_getTextureRect(building->dragged_sprite);
    sfVector2f pos = {mouse.x, mouse.y};

    pos.x -= rect.width / 2;
    pos.y -= rect.height / 2;
    disp_stats(building, win, game);
    sfRenderWindow_drawSprite(win, building->buy_fire, NULL);
    sfRenderWindow_drawSprite(win, building->buy_ice, NULL);
    sfRenderWindow_drawSprite(win, building->buy_poison, NULL);
    sfRenderWindow_drawSprite(win, building->buy_mid, NULL);
    if (building->is_dragged) {
        sfSprite_setPosition(building->dragged_sprite, pos);
        sfRenderWindow_drawSprite(win, building->dragged_sprite, NULL);
    }
}
