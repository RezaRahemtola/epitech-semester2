/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Functions to load assets in sprites
*/

#include "defender.h"

static void load_building_textures(textures_t *list)
{
    list->buy_fire = sfTexture_createFromFile("assets/buy_fire.png", NULL);
    list->buy_ice = sfTexture_createFromFile("assets/buy_ice.png", NULL);
    list->buy_poison = sfTexture_createFromFile("assets/buy_poison.png", NULL);
    list->buy_mid = sfTexture_createFromFile("assets/buy_mid.png", NULL);
}

textures_t *load_textures(void)
{
    textures_t *list = malloc(sizeof(textures_t));

    list->path = sfTexture_createFromFile("assets/path.png", NULL);
    list->floor = sfTexture_createFromFile("assets/floor.png", NULL);
    list->play = sfTexture_createFromFile("assets/play.png", NULL);
    list->spawn = sfTexture_createFromFile("assets/spawn.png", NULL);
    list->end = sfTexture_createFromFile("assets/end.png", NULL);
    list->exit = sfTexture_createFromFile("assets/exit.png", NULL);
    list->how_play = sfTexture_createFromFile("assets/how_play.png", NULL);
    list->build_bg = sfTexture_createFromFile("assets/build_bg.png", NULL);
    list->gold = sfTexture_createFromFile("assets/gold.png", NULL);
    list->kill = sfTexture_createFromFile("assets/kills.png", NULL);
    list->health = sfTexture_createFromFile("assets/heart.png", NULL);
    load_building_textures(list);
    return (list);
}

void free_textures(textures_t *textures)
{
    csfml_destroyer("tt", textures->path, textures->floor);
    csfml_destroyer("tt", textures->play, textures->exit);
    csfml_destroyer("tt", textures->buy_fire, textures->buy_ice);
    csfml_destroyer("tt", textures->buy_poison, textures->buy_mid);
    csfml_destroyer("tt", textures->build_bg, textures->gold);
    csfml_destroyer("tt", textures->kill, textures->how_play);
    csfml_destroyer("tt", textures->end, textures->spawn);
    csfml_destroyer("t", textures->health);
    free(textures);
}

void free_map_sprites(sfSprite ***sprites, char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            sfSprite_destroy(sprites[i][j]);
        }
        free(sprites[i]);
    }
    free(sprites);
}
