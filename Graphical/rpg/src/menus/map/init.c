/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Map initiolization
*/

#include <stdio.h>
#include "maps.h"
#include "my_arrays.h"
#include "my_math.h"
#include "my.h"

static void init_sprites(map_menu_t *menu)
{
    sfVector2f scale = { 1.5f, 1.5f };
    sfVector2f pos = { 0, 0 };

    sfSprite_setScale(menu->map_sprite, scale);
    sfSprite_setTexture(menu->map_sprite, menu->map_texture, sfFalse);
    sfSprite_setPosition(menu->map_sprite, pos);
    sfSprite_setScale(menu->objects_sprite, scale);
    sfSprite_setTexture(menu->objects_sprite, menu->objects_texture, sfFalse);
    sfSprite_setPosition(menu->objects_sprite, pos);
    pos.x -= (float) menu->offset_pos->x * scale.x;
    pos.y -= (float) menu->offset_pos->y * scale.y;
    sfSprite_setScale(menu->offset_sprite, scale);
    sfSprite_setTexture(menu->offset_sprite, menu->offset_texture, sfFalse);
    sfSprite_setPosition(menu->offset_sprite, pos);
}

static bool read_collisions(map_menu_t *menu, char *map)
{
    FILE *file = fopen(map, "r");
    size_t len = 0;
    int result = 0;
    bool out = false;

    menu->map_collisions = malloc(sizeof(char *) * (menu->map_size->y + 1));
    if (file == NULL || menu->map_collisions == NULL)
        return (false);
    for (int i = 0; i < menu->map_size->y + 1; i++) {
        menu->map_collisions[i] = NULL;
    }
    for (int i = 0; i < menu->map_size->y && result != -1; i++) {
        result = getline(&menu->map_collisions[i], &len, file);
        out = result == -1 && i != menu->map_size->y - 1;
        if ((result > 0 && result != menu->map_size->x + 1) || out)
            result = -1;
        menu->map_collisions[i][len - 1] = '\0';
    }
    fclose(file);
    return (my_arraylen(menu->map_collisions) == menu->map_size->y);
}

static void init_player_sprite(game_t *game)
{
    sfSprite *player = game->player->sprite;
    sfVector2u win = sfRenderWindow_getSize(game->window);
    sfVector2u text = sfTexture_getSize(game->player->textures[0]);
    sfVector2f pos = { win.x / 2 - text.x / 6, win.y / 2 - text.y / 1.5f};
    sfIntRect rect = { 0, 0, text.x / 4, text.y };

    sfSprite_setTexture(player, game->player->textures[0], sfTrue);
    sfSprite_setTextureRect(player, rect);
    sfSprite_setPosition(player, pos);
}

bool init_map_menu(game_t *game, map_menu_t *menu, char *files[5])
{
    bool config = init_map_config(menu, files[1]);
    bool collisions = read_collisions(menu, files[2]);

    if (!config || !collisions)
        return (false);
    menu->map_texture = sfTexture_createFromFile(files[0], NULL);
    menu->offset_texture = sfTexture_createFromFile(files[3], NULL);
    menu->objects_texture = sfTexture_createFromFile(files[4], NULL);
    if (menu->map_texture == NULL || menu->offset_texture == NULL)
        return (false);
    menu->map_sprite = sfSprite_create();
    menu->offset_sprite = sfSprite_create();
    menu->objects_sprite = sfSprite_create();
    menu->zoom = sfClock_create();
    menu->move = sfClock_create();
    menu->anim = sfClock_create();
    menu->music = sound_create("assets/music.ogg", sfTrue, sfTrue);
    init_player_sprite(game);
    init_sprites(menu);
    return (true);
}
