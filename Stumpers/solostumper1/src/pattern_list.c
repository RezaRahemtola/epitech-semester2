/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Functions for the pattern list
*/

#include <stdlib.h>
#include "countwords.h"

void my_putend(char *str, pattern_t **dest)
{
    pattern_t *list = *dest;
    pattern_t *obj = malloc(sizeof(pattern_t));

    obj->str = my_strdup(str);
    obj->nb = 1;
    obj->next = NULL;

    if (list == NULL) {
        *dest = obj;
        return;
    }
    while (list->next != NULL)
        list = list->next;
    list->next = obj;
}

void list_destroy(pattern_t *obj)
{
    pattern_t *tmp = NULL;

    while (obj != NULL) {
        tmp = obj;
        obj = obj->next;
        free(tmp->str);
        free(tmp);
    }
}

int is_in_list(char *str, pattern_t *list)
{
    for (int i = 1; list != NULL; i++) {
        if (my_strcmp(list->str, str) == 0)
            return (i);
        list = list->next;
    }
    return (-1);
}

char *get_pattern(char **str)
{
    int i = 0;
    char *pattern = NULL;

    while ((*str)[0] == ' ' || (*str)[0] == '\t') (*str)++;
    while ((*str)[i] != ' ' && (*str)[i] != '\t' && (*str)[i] != '\0')
        i++;
    pattern = my_malloc_str(i + 1, '\0');
    my_strncpy(pattern, *str, i);
    (*str) += i;
    while ((*str)[0] == ' ' || (*str)[0] == '\t') (*str)++;
    return (pattern);
}

void increment_pattern_count(int index, pattern_t *list)
{
    for (int i = 1; list != NULL; i++) {
        if (i == index)
            list->nb += 1;
        list = list->next;
    }
}
