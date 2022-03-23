/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** Functions to convert lists to other data structures
*/

#include <stdlib.h>
#include "mylist.h"

list_t *array_to_mylist(char **array, char *(*fptr)(const char *str))
{
    list_t *list = NULL;

    for (int i = 0; array[i] != NULL; i++) {
        if (fptr != NULL)
            mylist_append((*fptr)(array[i]), &list);
        else
            mylist_append(array[i], &list);
    }
    return (list);
}

char **mylist_to_array(list_t *list, char *(*fptr)(const char *str))
{
    int len = mylist_len(list);
    char **array = malloc(sizeof(char *) * (len + 1));

    if (array == NULL)
        return (NULL);
    for (int i = 0; list != NULL; i++) {
        if (fptr != NULL)
            array[i] = (*fptr)(list->data);
        else
            array[i] = list->data;
        list = list->next;
    }
    array[len] = NULL;
    return (array);
}
