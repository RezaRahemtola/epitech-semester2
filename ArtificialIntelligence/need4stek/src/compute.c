/*
** EPITECH PROJECT, 2022
** n4s
** File description:
** Functions to compute speed and direction
*/

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

void compute_direction(car_t *car)
{
    float current = car->wheels;

    if (car->lidar[31] <= 200)
        car->wheels = 0.1;
    if (car->lidar[0] <= 200)
        car->wheels = -0.1;
    if (car->lidar[15] >= 700) {
        change_direction(0);
        car->wheels = 0;
        return;
    }
    if (car->lidar[0] > car->lidar[31])
        car->wheels = 0.3;
    else
        car->wheels = -0.3;
    if (current != 0) {
        change_direction(car->wheels);
        car->wheels = 0;
    }
}

void compute_speed(car_t *car)
{
    float new = 0.3;

    if (car->lidar[15] >= 1000)
        new = 0.5;
    if (car->lidar[15] >= 1500)
        new = 0.75;
    if (car->lidar[15] >= 2000)
        new = 1;
    if (car->speed != new) {
        change_speed(new);
        car->speed = new;
    }
}
