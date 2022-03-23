/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Functions to perform actions on the map
*/

#include <stdio.h>
#include <unistd.h>
#include "defender.h"

char **load_map_from_file(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *tmp = NULL;
    char *buffer = NULL;
    char **map = NULL;
    size_t size = 0;

    if (file == NULL)
        return (NULL);
    while (getline(&tmp, &size, file) != -1) {
        buffer = my_newstrcat(buffer, tmp, true, true);
        tmp = NULL;
    }
    map = my_strsplit(buffer, '\n');
    free(buffer);
    free(tmp);
    fclose(file);
    return (map);
}

static sfTexture *get_texture(char **map, int x, int y, textures_t *textures)
{
    char square = map[x][y];
    char path[5] = { CHAR_UP, CHAR_DOWN, CHAR_LEFT, CHAR_RIGHT, '\0' };

    if (square == CHAR_SPAWN)
        return (textures->spawn);
    if (square == CHAR_END)
        return (textures->end);
    if (my_charinstr(square, path))
        return (textures->path);
    if (square == CHAR_FLOOR)
        return (textures->floor);
    if (square == CHAR_BUILD_BG)
        return (textures->build_bg);
    return (NULL);
}

static sfSprite *generate_sprite(char **map, sfVector2i *xy, textures_t *list)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2i max = { my_strlen(map[0]), my_arraylen(map) };
    sfVector2u size = { 0, 0 };
    sfVector2f pos = { 0, 0 };
    sfVector2f scale = { 0, 0 };

    sfSprite_setTexture(sprite, get_texture(map, xy->x, xy->y, list), sfFalse);
    size = sfTexture_getSize(sfSprite_getTexture(sprite));
    pos.x = (float) WIDTH / (float) max.x * (float) xy->y;
    pos.y = (float) HEIGHT / (float) max.y * (float) xy->x;
    scale.x = (float) WIDTH / (float) max.x / (float) size.x;
    scale.y = (float) HEIGHT / (float) max.y / (float) size.y;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

sfSprite ***generate_map(char **map, textures_t *list)
{
    int max_x = my_arraylen(map);
    int max_y = my_strlen(map[0]);
    int size = 0;
    sfSprite ***sprites = malloc(sizeof(sfSprite **) * max_x);
    sfSprite **row = NULL;
    sfVector2i xy = { 0, 0 };

    for (int i = 0; i < max_x; i++) {
        xy.x = i;
        row = malloc(sizeof(sfSprite *) * max_y);
        size = my_strlen(map[i]);
        for (int j = 0; j < size; j++) {
            xy.y = j;
            row[j] = generate_sprite(map, &xy, list);
        }
        sprites[i] = row;
    }
    return sprites;
}

void display_map(sfRenderWindow *window, char **map, sfSprite ***sprites)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            sfRenderWindow_drawSprite(window, sprites[i][j], NULL);
        }
    }
}
