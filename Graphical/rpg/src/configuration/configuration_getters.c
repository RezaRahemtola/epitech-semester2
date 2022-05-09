/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Configuration getting functions
*/

#include "configuration.h"
#include "my_string.h"

static bool is_same_key(configuration_pair_t *pair, char const *key)
{
    return my_strcmp(pair->key, key) == 0;
}

char *get_configuration_value(configuration_t *pairs, char const *key)
{
    configuration_pair_t *found = NULL;

    find_barray_element_cmp(pairs, found, is_same_key, key);
    return found == NULL ? NULL : found->value;
}

char *get_configuration_value_or_default(configuration_t *pairs,
char const *key, char const *default_value)
{
    char *found_value = get_configuration_value(pairs, key);
    char *new_value = my_strdup(default_value);

    if (found_value == NULL) {
        set_configuration_value(pairs, my_strdup(key), new_value);
        return new_value;
    } else {
        free(new_value);
        return found_value;
    }
}
