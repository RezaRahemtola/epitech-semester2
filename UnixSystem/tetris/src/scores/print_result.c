/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** print_score
*/

#include <ncurses.h>
#include <unistd.h>
#include "score.h"
#include "my_numbers.h"
#include <stdlib.h>

static void print_high_score(score_t *score, int y, WINDOW *score_screen)
{
    int len = my_nbrlen(score->first_place) / 2;

    mvwprintw(score_screen, 6, y - 5, "HIGH SCORE:");
    mvwprintw(score_screen, 8, y - 4, "1st:");
    mvwprintw(score_screen, 8, (y + 4) - len, "%d", score->first_place);
    len = my_nbrlen(score->second_place) / 2,
    mvwprintw(score_screen, 9, y - 4, "2nd:");
    mvwprintw(score_screen, 9, (y + 4) - len, "%d", score->second_place);
    len = my_nbrlen(score->third_place) / 2,
    mvwprintw(score_screen, 10, y - 4, "3rd:");
    mvwprintw(score_screen, 10, (y + 4) - len, "%d", score->third_place);
}

static void print_your_score(score_t *score, int y, WINDOW *score_screen)
{
    int len = my_nbrlen(score->current_score) / 2;

    mvwprintw(score_screen, 13, y - 5, "YOUR SCORE:");
    mvwprintw(score_screen, 15, y - len, "%d", score->current_score);
}

void print_result(size_t current, int key_quit)
{
    WINDOW *score_screen = NULL;
    score_t *score = init_score(current);
    int x = 0;
    int y = 0;

    clear();
    refresh();
    get_new_ranking(score);
    getmaxyx(stdscr, x, y);
    x *= 0.5;
    y *= 0.5;
    score_screen = newwin(x, y, (x / 2), (y / 2));
    box(score_screen, 0, 0);
    mvwprintw(score_screen, 2, (y / 2) - 3, "RESULT");
    print_high_score(score, y / 2, score_screen);
    print_your_score(score, y / 2, score_screen);
    wrefresh(score_screen);
    stock_score(score);
    free(score);
    while (getch() != key_quit);
}
