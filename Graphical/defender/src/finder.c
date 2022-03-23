/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** Character finder
*/

#include <math.h>
#include "defender.h"

void update_direction(enemy_t *enemy, game_t *game, info_t *info)
{
    sfVector2f up = { -0.1f, 0 };
    sfVector2f down = { 0.1f, 0 };
    sfVector2f left = { 0, -0.1f };
    sfVector2f right = { 0, 0.1f };
    sfVector2i ints = { (int) enemy->pos->x, (int) enemy->pos->y };
    sfVector2f vectors[4] = { up, down, left, right };
    char chars[4] = { CHAR_UP, CHAR_DOWN, CHAR_LEFT, CHAR_RIGHT };
    char pos = info->map[ints.x][ints.y];

    if (pos == CHAR_END) {
        game->hp -= enemy->type->damage;
        sfSound_play(game->death_sound->sound);
        remove_enemy(&game->enemies, enemy);
    }
    for (int i = 0; i < 4; i++) {
        if (pos == chars[i]) {
            enemy->dir->x = vectors[i].x;
            enemy->dir->y = vectors[i].y;
        }
    }
}

sfVector2f *find_spawn(char **map)
{
    int size = my_arraylen(map);
    int len = my_strlen(map[0]);
    int x = 0;
    int y = 0;
    sfVector2f *vec = NULL;

    for (int i = 0; i < size * len; i++) {
        x = i / len;
        y = i % len;
        if (map[x][y] == CHAR_SPAWN) {
            vec = malloc(sizeof(sfVector2f));
            vec->x = (float) (x + 0.5);
            vec->y = (float) (y + 0.5);
            return (vec);
        }
    }
    return NULL;
}

sfVector2f *find_end(char **map)
{
    int size = my_arraylen(map);
    int len = my_strlen(map[0]);
    int x = 0;
    int y = 0;
    sfVector2f *vec = NULL;

    for (int i = 0; i < size * len; i++) {
        x = i / len;
        y = i % len;
        if (map[x][y] == CHAR_END) {
            vec = malloc(sizeof(sfVector2f));
            vec->x = (float) (x + 0.5);
            vec->y = (float) (y + 0.5);
            return (vec);
        }
    }
    return NULL;
}

float get_distance(sfVector2f *vec1, sfVector2f *vec2)
{
    return (sqrtf(powf(vec1->x + vec2->x, 2) + powf(vec1->y + vec2->y, 2)));
}
