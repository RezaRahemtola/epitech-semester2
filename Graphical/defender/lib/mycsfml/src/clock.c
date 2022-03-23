/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Clock
*/

#include <stdlib.h>
#include "mycsfml_clock.h"

time_clock_t *clock_create(void)
{
    time_clock_t *obj = malloc(sizeof(time_clock_t));
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float time_seconds = sfTime_asSeconds(time);

    obj->clock = clock;
    obj->time = time;
    obj->time_seconds = time_seconds;
    return (obj);
}

void clock_destroy(time_clock_t *obj)
{
    sfClock_destroy(obj->clock);
    free(obj);
}

void clock_update_time(time_clock_t *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->time_seconds = sfTime_asSeconds(obj->time);
}
