/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Data load and save management
*/

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void *load_data(char const *filepath, size_t data_size)
{
    FILE *file = fopen(filepath, "r");
    void *data = malloc(data_size);

    if (file == NULL || data == NULL) {
        free(data);
        return NULL;
    }
    fread(data, data_size, 1, file);
    if (fclose(file) == EOF) {
        free(data);
        return NULL;
    }
    return data;
}

bool save_data(char const *filepath, void *data, size_t data_size)
{
    FILE *file = fopen(filepath, "w");

    if (file == NULL || data == NULL)
        return false;
    fwrite(data, data_size, 1, file);
    if (fclose(file) == EOF)
        return false;
    return true;
}
