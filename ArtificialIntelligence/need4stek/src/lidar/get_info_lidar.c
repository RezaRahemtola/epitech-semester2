/*
** EPITECH PROJECT, 2022
** GET_INFO_LIDAR_C
** File description:
** get_info_lidar
*/

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "my_string.h"
#include "my.h"

static void add_lidar_in_car(car_t *car, char **lidar_info)
{
    int i = 3;
    int verif = 0;;

    while (lidar_info[verif])
        verif++;
    if (verif < 34)
        return;
    for (; i < 35; i++)
        car->lidar[i - 3] = atof(lidar_info[i]);
}

void get_info_lidar(car_t *car)
{
    char *content = NULL;
    char **lidar_info = NULL;
    size_t read = 0;

    dprintf(STDOUT, "GET_INFO_LIDAR\n");
    if (getline(&content, &read, stdin) == -1)
        return;
    lidar_info = my_strsplit(content, ':');
    if (lidar_info == NULL) {
        free(content);
        return;
    } else if (is_end_array(lidar_info)) {
        free(content);
        car->end = true;
        return;
    }
    add_lidar_in_car(car, lidar_info);
    free(content);
    my_free_arrays(1, lidar_info);
}
