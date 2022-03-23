/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Functions of the game loop
*/

#include "defender.h"

static int handle_game_events(sfRenderWindow *window, building_t *building,
info_t *info, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_closing_event(window, event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return (1);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR)
            game->display_range = !game->display_range;
        if (event.type == sfEvtMouseButtonPressed ||
        event.type == sfEvtMouseButtonReleased)
            check_building_menu_click(&event, building, info, game);
    }
    return (0);
}

static void display_stats_texts(sfRenderWindow *window, text_t *kills,
text_t *spent, text_t *left)
{
    sfRenderWindow_drawText(window, kills->text, NULL);
    sfRenderWindow_drawText(window, spent->text, NULL);
    sfRenderWindow_drawText(window, left->text, NULL);
    sfRenderWindow_display(window);
}

static void end_stats(sfRenderWindow *window, game_t *game)
{
    sfTexture *bg = sfTexture_createFromFile("assets/end_stats.png", NULL);
    char *kills_txt = my_nb_to_str(game->kills);
    text_t *kills = text_create(kills_txt, "assets/score.otf", sfBlack, 45);
    char *spent_txt = my_nb_to_str(game->spent);
    text_t *spent = text_create(spent_txt, "assets/score.otf", sfBlack, 45);
    char *left_txt = my_nb_to_str(game->gold);
    text_t *left = text_create(left_txt, "assets/score.otf", sfBlack, 45);

    sfText_setPosition(kills->text, (sfVector2f){430, 260});
    sfText_setPosition(spent->text, (sfVector2f){645, 425});
    sfText_setPosition(left->text, (sfVector2f){635, 600});
    while (sfRenderWindow_isOpen(window) && !handle_key_event(window)) {
        sfRenderWindow_clear(window, sfBlack);
        disp_texture(bg, window);
        display_stats_texts(window, kills, spent, left);
    }
    free(kills_txt);
    free(spent_txt);
    free(left_txt);
    csfml_destroyer("TTTt", kills, spent, left, bg);
}

static void display_elements(sfRenderWindow *window, info_t *info,
game_t *game, building_t *building)
{
    display_map(window, info->map, info->squares);
    display_building(building, window, game);
    display_enemies(window, game->enemies);
    display_towers(window, game);
}

void play(info_t *info, sfRenderWindow *window, textures_t *textures)
{
    game_t *game = init_game(info);
    bool goto_start = false;
    building_t *building = init_building(textures);
    sound_t *music = sound_create("assets/looping.ogg", sfTrue, sfTrue);

    sfSound_setVolume(music->sound, 50);
    while (sfRenderWindow_isOpen(window) && !goto_start && game->hp > 0) {
        if (handle_game_events(window, building, info, game) == 1)
            goto_start = pause_menu(window);
        sfRenderWindow_clear(window, sfBlack);
        update_enemies(game, info);
        update_towers(game);
        display_elements(window, info, game, building);
        sfRenderWindow_display(window);
    }
    free_building(building);
    csfml_destroyer("S", music);
    end_stats(window, game);
    free_game(game);
    start_menu(info, window, textures);
}
