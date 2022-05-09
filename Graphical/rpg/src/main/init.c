/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Game initialization
*/

#include <stdbool.h>
#include <stdlib.h>
#include "hud.h"
#include "main_menu.h"
#include "my_arrays.h"
#include "my_math.h"
#include "my_string.h"
#include "my.h"
#include "rpg.h"

static void init_array_in_config(configuration_t *config, int **ptr, char *key)
{
    char *temp = GCVOR(config, key, "");
    char **array = my_strsplit(temp, '/');

    *ptr = malloc(sizeof(int) * my_arraylen(array));
    for (int i = 0; array[i] != NULL; i++)
        ptr[0][i] = my_getnbr(array[i]);
    my_free_arrays(1, array);
}

static bool init_global_config(game_t *game)
{
    configuration_t *config = load_configuration("assets/game.conf", false);
    game->config = malloc(sizeof(global_t));

    if (config == NULL || game->config == NULL)
        return (false);
    game->config->mobs = my_strsplit(GCVOR(config, "mobs", ""), '/');
    game->config->npcs = my_strsplit(GCVOR(config, "npcs", ""), '/');
    game->config->def_hp = my_getnbr(GCVOR(config, "default-hp", "0"));
    game->config->def_points = my_getnbr(GCVOR(config, "default-points", "0"));
    game->config->level_max = my_getnbr(GCVOR(config, "level-max", "0"));
    game->config->xp = NULL;
    game->config->points = NULL;
    init_array_in_config(config, &game->config->xp, "xp");
    init_array_in_config(config, &game->config->points, "points");
    destroy_configuration(config);
    return (true);
}

void add_button(buttons_t **list, buttons_t *button)
{
    buttons_t *current = *list;

    if (*list == NULL) {
        *list = button;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = button;
}

static settings_t *init_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    if (settings == NULL)
        return (NULL);
    settings->width = 1920;
    settings->height = 1080;
    settings->fullscreen = true;
    settings->vsync = false;
    settings->framerate = 60;
    settings->volume = 100;
    return (settings);
}

bool init_game(game_t *game)
{
    game->player = malloc(sizeof(player_t));
    game->hud = malloc(sizeof(hud_t));
    game->settings = init_settings();
    if (!game->player || !init_global_config(game) || !game->settings) {
        my_dprintf(2, "Error: Failed to initialize settings or config\n");
        return (false);
    }
    game->click_sound = sound_create("assets/click_sound.ogg", false, false);
    game->window = init_window(game->settings);
    if (game->window == NULL || !init_player(game->player)) {
        my_dprintf(2, "Error: Failed to initialize window or player\n");
        return (false);
    } else if (game->hud == NULL || !init_hud(game->hud, game)) {
        my_dprintf(2, "Error: Failed to initialize HUD\n");
        return (false);
    }
    game->main_menu = init_main_menu(game);
    init_entities(game);
    return (game->main_menu != NULL);
}
