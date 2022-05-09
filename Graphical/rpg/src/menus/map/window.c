/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Map display window
*/

#include <stdlib.h>
#include "hud.h"
#include "maps.h"
#include "rpg.h"
#include "particles.h"

static void destroy_menu(map_menu_t *menu)
{
    sfTexture_destroy(menu->map_texture);
    sfTexture_destroy(menu->offset_texture),
    sfTexture_destroy(menu->objects_texture);
    sfSprite_destroy(menu->map_sprite);
    sfSprite_destroy(menu->offset_sprite);
    sfSprite_destroy(menu->objects_sprite);
    sfClock_destroy(menu->zoom);
    sfClock_destroy(menu->move);
    sfClock_destroy(menu->anim);
    my_free(3, menu->map_size, menu->map_default_pos, menu->offset_pos);
    my_free_arrays(1, menu->map_collisions);
    sound_destroy(menu->music);
    free(menu);
}

static void map_loop(game_t *game, map_menu_t *menu)
{
    particle_t *rain = make_rain();

    while (game->playing && sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        handle_map_events(game, menu->music->sound);
        if (!handle_movement(menu, game)) {
            handle_zoom(menu, game);
        }
        sfRenderWindow_drawSprite(game->window, menu->offset_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, menu->map_sprite, NULL);
        draw_mobs_before(game);
        sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
        draw_mobs(game, menu);
        update_particles(rain, game->window);
        render_particles(rain, game->window);
        sfRenderWindow_drawSprite(game->window, menu->objects_sprite, NULL);
        draw_hud(game->hud, game);
        sfRenderWindow_display(game->window);
    }
}

void display_map(game_t *game, char *files[5])
{
    map_menu_t *menu = malloc(sizeof(map_menu_t));

    if (menu == NULL) {
        return;
    } else if (!init_map_menu(game, menu, files)) {
        free(menu);
    } else {
        set_default_position(game, menu);
        refresh_offset(menu);
        refresh_mobs(game, menu);
        game->playing = true;
        map_loop(game, menu);
        destroy_menu(menu);
    }
}
