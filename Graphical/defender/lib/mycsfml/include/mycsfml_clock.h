/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Clock.h
*/

#ifndef MYCSFML_CLOCK_H_
    #define MYCSFML_CLOCK_H_
    #include <SFML/System/Clock.h>

typedef struct time_clock_s {
    sfClock *clock;
    sfTime time;
    float time_seconds;
} time_clock_t;

time_clock_t *clock_create(void);
void clock_destroy(time_clock_t *obj);
void clock_update_time(time_clock_t *obj);

#endif /* !MYCSFML_CLOCK_H_ */
