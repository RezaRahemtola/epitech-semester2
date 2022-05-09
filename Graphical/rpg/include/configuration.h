/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Configuration header file
*/

#pragma once

#include "better_arrays.h"

typedef struct configuration_pair {
    char *key;
    char *value;
} configuration_pair_t;

#define GCVOR(x, y, z) get_configuration_value_or_default(x, y, z)

typedef barray(configuration_pair_t) configuration_t;

configuration_t *load_configuration(char const *filepath, bool fail_fast);
bool save_configuration(char const *filepath, configuration_t *pairs);
char *get_configuration_value(configuration_t *pairs, char const *key);
char *get_configuration_value_or_default(configuration_t *pairs,
    char const *key, char const *default_value);
// Return true if needed to create pair, false otherwise
bool set_configuration_value(configuration_t *pairs, char const *key,
    char const *value);
void destroy_configuration(configuration_t *pairs);
