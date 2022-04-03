/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions to handle game scores
*/

#include <time.h>
#include <stdlib.h>
#include "game.h"
#include "score.h"
#include "my_strings.h"
#include "my_numbers.h"

scores_t *init_scores(int level)
{
    scores_t *score = malloc(sizeof(scores_t));

    score->level = level;
    score->lines = 0;
    score->timer = init_timer(CLOCKS_PER_SEC);
    score->score = 0;
    score->high_score = get_score(1);
    return (score);
}

WINDOW *get_scores_win(int width, int height)
{
    static WINDOW *scores_win = NULL;

    if (scores_win == NULL)
        scores_win = newwin(height + 2, width + 2, 1, 1);
    return (scores_win);
}

static void get_spaces(int len_name, int len_data, char **spaces)
{
    int len = 18 - len_name - len_data;
    char *str = my_str_allocfill(len + 1, ' ');

    str[len] = '\0';
    free(*spaces);
    *spaces = str;
}

static void print_scores(scores_t *scores, char *timer, WINDOW *scorescr)
{
    char *spaces = NULL;

    get_spaces(11, my_nbrlen(scores->high_score), &spaces);
    mvwprintw(scorescr, 2, 2, "High Score:%s%d", spaces, scores->high_score);
    get_spaces(6, my_nbrlen(scores->score), &spaces);
    mvwprintw(scorescr, 4, 2, "Score:%s%d", spaces, scores->score);
    get_spaces(6, my_nbrlen(scores->lines), &spaces);
    mvwprintw(scorescr, 7, 2, "Lines:%s%d", spaces, scores->lines);
    get_spaces(6, my_nbrlen(scores->level), &spaces);
    mvwprintw(scorescr, 9, 2, "Level:%s%d", spaces, scores->level);
    get_spaces(6, my_strlen(timer), &spaces);
    mvwprintw(scorescr, 12, 2, "Timer:%s%s", spaces, timer);
    free(spaces);
}

void display_scores(game_t *game)
{
    WINDOW *scorescr = get_scores_win(20, 13);
    char *timer = get_timer_str(game->scores->timer->elapsed);

    wclear(scorescr);
    box(scorescr, 0, 0);
    print_scores(game->scores, timer, scorescr);
    free(timer);
    wrefresh(scorescr);
}
