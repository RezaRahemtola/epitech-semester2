/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Functions to display pokemons
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stumper.h"
#include "my_strings.h"

bonobo_t *get_bono_by_name(list_t *bonobos, char *name)
{
    list_t *list = bonobos;
    bonobo_t *bono = NULL;

    while (list != NULL) {
        bono = list->data;
        if (strcmp(bono->name, name) == 0)
            return (bono);
        list = list->next;
    }
    return (NULL);
}

static char *get_upname(char *name)
{
    char *str = NULL;

    if (name == NULL)
        return NULL;
    str = my_strdup(name);
    if (str == NULL)
        return NULL;
    my_strupcase(str);
    return (str);
}

static char *get_smallest_name(list_t *bonobos, char *name)
{
    char *upsmallest = NULL;
    char *upname = get_upname(name);
    char *smallest = NULL;
    list_t *list = bonobos;
    bonobo_t *bono = NULL;

    while (list != NULL) {
        bono = list->data;
        if ((upsmallest == NULL || my_strcmp(upsmallest, bono->upname) > 0)
            && my_strcmp(bono->upname, upname) > 0) {
            smallest = bono->name;
            upsmallest = bono->upname;
        }
        list = list->next;
    }
    free(upname);
    return (smallest);
}

void display_bonobos(list_t *bonobos)
{
    char *name = get_smallest_name(bonobos, NULL);
    bonobo_t *bono = NULL;

    while (name != NULL) {
        bono = get_bono_by_name(bonobos, name);
        printf(
            "Pokemon %s has %d attack, %d defense, %d speed and %d health\n",
            bono->name, bono->attack, bono->defense, bono->speed,
            bono->health);
        name = get_smallest_name(bonobos, name);
    }
}
