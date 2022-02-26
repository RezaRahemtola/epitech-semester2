/*
** EPITECH PROJECT, 2022
** SoloStumper1
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "countwords.h"

static void disp_words(pattern_t *list)
{
    while (list != NULL) {
        printf("%s: %d\n", list->str, list->nb);
        list = list->next;
    }
}

void countwords(char *str)
{
    pattern_t *list = NULL;
    char *pattern = NULL;
    int index = -1;

    while (str[0] != '\0') {
        pattern = get_pattern(&str);
        index = is_in_list(pattern, list);
        if (index == -1)
            my_putend(pattern, &list);
        else
            increment_pattern_count(index, list);
        free(pattern);
    }
    disp_words(list);
    list_destroy(list);
}
