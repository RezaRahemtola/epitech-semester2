/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** clock
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "my.h"

char *int_to_str(size_t nb)
{
    int tmp = nb;
    int size = my_nbrlen(nb);
    int i = 1;
    char *str = my_str_allocfill(sizeof(char) * size + 2, '\0');

    if (size == 1) {
        str[0] = '0';
        i--;
    }
    for (; i < size + 1; i++) {
        tmp = nb;
        while (tmp >= 10)
            tmp %= 10;
        str[size - i] = tmp + '0';
        nb /= 10;
    }
    return (str);
}

char *get_timer_str(size_t time)
{
    size_t hours = time / 3600;
    size_t minutes = 0;
    size_t seconds = 0;
    char *h = NULL;
    char *m = NULL;
    char *s = NULL;
    char *result = NULL;

    time -= 3600 * (time / 3600);
    minutes = time / 60;
    time -= 60 * (time / 60);
    seconds = time;
    h = int_to_str(hours);
    m = int_to_str(minutes);
    s = int_to_str(seconds);
    result = my_stringf("%s:%s:%s", h, m, s);
    free(h);
    free(m);
    free(s);
    return (result);
}

time_clock_t *init_timer(size_t delay)
{
    time_clock_t *timer = malloc(sizeof(time_clock_t));

    timer->elapsed = 0;
    timer->delay = delay;
    timer->start = clock();
    return (timer);
}

bool is_time_elapsed(time_clock_t *timer)
{
    if (clock() - timer->start > timer->delay) {
        timer->start = clock();
        timer->elapsed++;
        return (true);
    }
    return (false);
}

void update_level(game_t *game)
{
    if (game->scores->lines % 10 == 0 && game->scores->lines != 0) {
        game->scores->level++;
        game->scores->score += SCORE_LEVEL;
    }
    game->timer->delay = CLOCKS_PER_SEC;
    for (int i = 0; i < game->scores->level; i++)
        game->timer->delay -= (game->timer->delay * 0.10);
}
