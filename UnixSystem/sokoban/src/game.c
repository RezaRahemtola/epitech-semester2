/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Main functions of the sokoban game
*/

#include <ncurses.h>
#include "sokoban.h"

static void display_resize_term_error(void)
{
    char *str = "Wrong size";
    int x = getmaxx(stdscr) / 2 - (my_strlen(str) / 2);
    int y = getmaxy(stdscr) / 2;

    mvaddstr(y, x, str);
}

static void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        printw("%s\n", map[i]);
}

static void play(char **map, char **base, int key)
{
    char current = '\0';

    move_player(map, key);
    for (int i = 0; base[i] != NULL; i++) {
        for (int j = 0; base[i][j] != '\0'; j++) {
            current = map[i][j];
            map[i][j] = (base[i][j] == 'O' && current == ' ') ? 'O' : current;
        }
    }
    display_map(map);
}

static void reset_map(char **map, char **base)
{
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
        map[i] = my_strdup(base[i]);
    }
}

bool sokoban(char **map, char **base)
{
    int key = 0;

    initscr();
    noecho();
    keypad(stdscr, true);
    while (!is_endgame(map, base)) {
        if (key == ' ')
            reset_map(map, base);
        clear();
        if (!map_has_size_for_window(map, getmaxx(stdscr), getmaxy(stdscr)))
            display_resize_term_error();
        else
            play(map, base, key);
        if (!is_endgame(map, base))
            key = getch();
        refresh();
    }
    clear();
    endwin();
    return (all_boxes_on_storage(map, base));
}
