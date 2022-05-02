/*
** EPITECH PROJECT, 2022
** need4steck
** File description:
** AI
*/

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

static bool back_car(car_t *car)
{
    int count = 0;

    for (int i = 0; i < 32; i++) {
        if (car->lidar[i] == 0)
            count++;
    }
    if (count == 0 && car->lidar[15] >= 100)
        return false;
    change_direction(0);
    change_speed(0.3);
    return true;
}

static void game_loop(car_t *car)
{
    get_info_lidar(car);
    if (!back_car(car)) {
        compute_speed(car);
        compute_direction(car);
    }
}

void ai(void)
{
    car_t car;

    if (!init_car(&car)) {
        dprintf(STDERR, "Error: Can't init car\n");
        return;
    }
    car.end = send_first_instructions(&car);
    while (!car.end) {
        game_loop(&car);
    }
    dprintf(STDOUT, "STOP_SIMULATION\n");
    destroy_car(&car);
}
