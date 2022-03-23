/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Core game functions
*/

#include "defender.h"

static void free_info(info_t *info)
{
    free_map_sprites(info->squares, info->map);
    my_free_2d_array(info->map);
    free(info->spawn);
    free(info->end);
    free(info->scale);
    free_types(info);
    free(info);
}

void defender(char *filepath)
{
    sfRenderWindow *window = create_window(WIDTH, HEIGHT, "Defender", 60);
    textures_t *textures = load_textures();
    info_t *info = malloc(sizeof(info_t));

    info->map = load_map_from_file(filepath);
    if (info->map == NULL)
        return;
    info->spawn = find_spawn(info->map);
    info->end = find_end(info->map);
    if (info->spawn == NULL)
        return;
    info->scale = malloc(sizeof(sfVector2f));
    info->scale->x = (float) WIDTH / (float) my_strlen(info->map[0]);
    info->scale->y = (float) HEIGHT / (float) my_arraylen(info->map);
    info->squares = generate_map(info->map, textures);
    generate_types(info);
    start_menu(info, window, textures);
    free_textures(textures);
    free_info(info);
    csfml_destroyer("w", window);
}
