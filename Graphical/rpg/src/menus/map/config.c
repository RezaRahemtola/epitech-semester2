/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Config getters
*/

#include "maps.h"
#include "my_math.h"

static void fill_values(configuration_t *config, char *keys[6], int *values[6])
{
    char *tmp = NULL;

    for (int i = 0; i < 6; i++) {
        tmp = get_configuration_value(config, keys[i]);
        if (tmp == NULL)
            continue;
        *values[i] = my_getnbr(tmp);
    }
}

bool init_map_config(map_menu_t *menu, char *conf)
{
    configuration_t *config = load_configuration(conf, false);
    sfVector2i *size = malloc(sizeof(sfVector2i));
    sfVector2i *def = malloc(sizeof(sfVector2i));
    sfVector2i *off = malloc(sizeof(sfVector2i));
    char *keys[6] = { "size_x", "size_y", "default_x", "default_y", \
    "offset_x", "offset_y" };
    int *val[6] = { &size->x, &size->y, &def->x, &def->y, &off->x, &off->y };

    if (config == NULL)
        return (false);
    fill_values(config, keys, val);
    menu->map_size = size;
    menu->map_default_pos = def;
    menu->offset_pos = off;
    destroy_configuration(config);
    return (true);
}
