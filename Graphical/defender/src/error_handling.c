/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** error handling
*/

#include <stdio.h>
#include <stdlib.h>
#include "defender.h"
#include "my.h"

static bool check_characters(char *buffer)
{
    bool invalid = false;
    int spawn_count = my_strcount(buffer, "S");
    int end_count = my_strcount(buffer, "E");
    char allowed[10] = { CHAR_SPAWN, CHAR_RIGHT, CHAR_LEFT, CHAR_DOWN, \
    CHAR_FLOOR, CHAR_BUILD_BG, CHAR_UP, CHAR_END, '\n', '\0' };

    for (int i = 0; !invalid && buffer[i] != '\0'; i++) {
        if (!my_charinstr(buffer[i], allowed))
            invalid = true;
    }
    if (spawn_count != 1 || end_count != 1)
        invalid = true;
    return (invalid);
}

static bool check_map_content(char *buffer)
{
    bool invalid = false;
    char **map = NULL;
    int len = 0;

    if (buffer == NULL || my_strlen(buffer) == 0)
        return (true);
    invalid = check_characters(buffer);
    map = my_strsplit(buffer, '\n');
    len = my_strlen(map[0]);
    for (int i = 0; !invalid && map[i] != NULL; i++) {
        if (my_strlen(map[i]) != len)
            invalid = true;
        len = my_strlen(map[i]);
    }
    free(buffer);
    my_free_2d_array(map);
    return (invalid);
}

static bool check_file(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *buffer = NULL;
    char *tmp = NULL;
    bool invalid_map = false;
    size_t size = 0;

    if (file == NULL)
        return (true);
    while (getline(&tmp, &size, file) != -1) {
        buffer = my_newstrcat(buffer, tmp, true, true);
        tmp = NULL;
    }
    invalid_map = check_map_content(buffer);
    free(tmp);
    fclose(file);
    return (invalid_map);
}

bool check_errors(int argc, char **argv)
{
    char *str = NULL;

    if (argc != 1 && argc != 2) {
        str = my_stringf("%s: bad arguments: %d", argv[0], argc - 1);
        my_puterror(str);
        my_puterror(" given but 1 required\nretry with -h\n");
        free(str);
        return (true);
    }
    if (check_file(argv[1])) {
        my_puterror("Invalid map.\nretry with -h\n");
        return (true);
    }
    return (false);
}
