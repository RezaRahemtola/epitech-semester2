/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Configuration parsing utilities
*/

#include <stdio.h>
#include "configuration.h"
#include "my_string.h"

static bool is_ignored_line(char const *line)
{
    switch (line[0]) {
        case '#':
        case '\0':
        case '\n':
            return true;
        default:
            return false;
    }
}

static bool is_invalid_line(char *line)
{
    return my_strchr(line, '=') == NULL || my_strchr(line, '=')[1] == '\0';
}

static void add_to_configuration(configuration_t *configuration, char *line)
{
    char *separator = my_strchr(line, '=');
    char *key;
    char *value;

    if (separator == NULL || line[0] == '=' || separator[1] == '\0')
        return;
    value = my_strndup(separator + 1, my_strlen(separator + 1));
    key = my_strndup(line, my_strlen(line) - my_strlen(value) - 1);
    set_configuration_value(configuration, key, value);
    free(key);
    free(value);
}

configuration_t *load_configuration(char const *filepath, bool fail_fast)
{
    configuration_t *config = new_barray(configuration_pair_t, 1);
    FILE *file = fopen(filepath, "r");
    size_t size = 0;
    ssize_t size_read;
    char *buffer = NULL;

    if (file == NULL)
        return NULL;
    for (size_read = getline(&buffer, &size, file); size_read != -1;
    size_read = getline(&buffer, &size, file)) {
        buffer[size_read - 1] = '\0';
        if (is_ignored_line(buffer))
            continue;
        if (is_invalid_line(buffer) && fail_fast) {
            destroy_configuration(config);
            return NULL;
        }
        add_to_configuration(config, buffer);
    }
    return free(buffer), fclose(file), config;
}

bool save_configuration(char const *filepath, configuration_t *config)
{
    FILE *file = fopen(filepath, "w");
    size_t i;

    if (file == NULL)
        return false;
    for (i = 0; i < config->size; i++) {
        fwrite(config->data[i].key, my_strlen(config->data[i].key), 1, file);
        fwrite("=", 1, 1, file);
        fwrite(config->data[i].value,
            my_strlen(config->data[i].value), 1, file);
        fwrite("\n", 1, 1, file);
    }
    fclose(file);
    return true;
}
