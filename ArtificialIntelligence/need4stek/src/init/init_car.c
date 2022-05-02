/*
** EPITECH PROJECT, 2022
** INIT_CAR_STRUCT_C
** File description:
** init_car_struct
*/

#include <stdlib.h>
#include "ai.h"

bool init_car(car_t *car)
{
    if (car == NULL)
        return false;
    car->end = false;
    car->speed = 0.4;
    car->wheels = 0;
    car->lidar = malloc(sizeof(float) * 32);
    if (car->lidar == NULL)
        return false;
    for (int i = 0; i < 32; i++)
        car->lidar[i] = 2000;
    return true;
}

void destroy_car(car_t *car)
{
    if (car == NULL)
        return;
    free(car->lidar);
}
