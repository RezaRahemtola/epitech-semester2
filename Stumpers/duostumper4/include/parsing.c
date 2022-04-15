/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Parsing
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "my.h"
#include "stumper.h"

static bonobo_t *destroy_bonobo(char **elems)
{
    bonobo_t *bono = malloc(32);

    if (!my_str_isnum(elems[1]) || !my_str_isnum(elems[2])
        || !my_str_isnum(elems[3]) || !my_str_isnum(elems[4])) {
        free(bono);
        return NULL;
    }
    if (bono == NULL)
        return NULL;
    bono->name = my_strdup(elems[0]);
    bono->upname = my_strdup(elems[0]);
    my_strupcase(bono->upname);
    bono->attack = atoi(elems[1]);
    bono->defense = atoi(elems[2]);
    bono->speed = atoi(elems[3]);
    bono->health = atoi(elems[4]);
    return (bono);
}

void init_bonobo(void *bono)
{
    bonobo_t *bonobo = bono;

    if (bono == NULL)
        return;
    free(bonobo->name);
    free(bonobo->upname);
    free(bonobo);
}

static void get_bono_from_line(char *buffer, list_t **list)
{
    char **array = NULL;
    bonobo_t *bono = NULL;

    if (buffer == NULL || buffer[0] == '#')
        return;
    array = my_strsplit(buffer, ';');
    if (my_arraylen(array) != 5) {
        my_free_2d_array(array);
        return;
    }
    bono = destroy_bonobo(array);
    if (bono != NULL)
        mylist_append(bono, list);
    my_free_2d_array(array);
}

static void get_bono_from_file(char *filename, list_t **list)
{
    char *filepath = my_stringf("pokecfg/%s", filename);
    FILE *file = fopen(filepath, "r");
    char *buffer = NULL;
    int size = 0;
    size_t read = 0;

    if (file == NULL) {
        perror("file parsing:");
        free(filepath);
        return;
    }
    while ((size = getline(&buffer, &read, file)) != -1) {
        if (buffer[size - 1] == '\n')
            buffer[size - 1] = '\0';
        get_bono_from_line(buffer, list);
    }
    free(buffer);
    free(filepath);
    fclose(file);
}

list_t *get_bonobos(void)
{
    DIR *d = opendir("pokecfg/");
    struct dirent *dir;
    list_t *list = NULL;

    if (d == NULL)
        return (NULL);
    while ((dir = readdir(d)) != NULL) {
        get_bono_from_file(dir->d_name, &list);
    }
    closedir(d);
    return (list);
}
