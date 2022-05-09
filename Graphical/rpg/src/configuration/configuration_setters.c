/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Configuration setting functions
*/

#include "configuration.h"
#include "my_string.h"

static bool is_same_key(configuration_pair_t *pair, char const *key)
{
    return my_strcmp(pair->key, key) == 0;
}

bool set_configuration_value(configuration_t *pairs, char const *key,
    char const *value)
{
    configuration_pair_t *found = NULL;
    configuration_pair_t new_pair;

    find_barray_element_cmp(pairs, found, is_same_key, key);
    if (found == NULL) {
        new_pair.key = my_strdup(key);
        new_pair.value = my_strdup(value);
        add_barray_element(pairs, new_pair);
        return true;
    } else if (my_strcmp(found->value, value) != 0) {
        free(found->value);
        found->value = my_strdup(value);
        return false;
    } else
        return false;
}

void destroy_configuration(configuration_t *pairs)
{
    foreach_barray_element(pairs, element) {
        free(element->value);
        free(element->key);
    }
    free(pairs->data);
    free(pairs);
}
