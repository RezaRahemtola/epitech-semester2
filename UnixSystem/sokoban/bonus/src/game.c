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

static void display_map(char **map, unsigned int moves)
{
    int color = COLOR_DEFAULT;
    int height = (getmaxy(stdscr) - my_arraylen(map)) / 2;
    int width = (getmaxx(stdscr) - my_strlen(map[0])) / 2;

    printw("Moves: %u\n", moves);
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'P')
                color = COLOR_PLAYER;
            if (map[i][j] == 'X')
                color = COLOR_BOX;
            if (map[i][j] == 'O')
                color = COLOR_STORAGE;
            attron(COLOR_PAIR(color));
            mvprintw(height + i, width + j, "%c", map[i][j]);
            attroff(COLOR_PAIR(color));
            color = COLOR_DEFAULT;
        }
    }
}

static void play(char **map, char **base, int key, unsigned int *moves)
{
    char current = '\0';

    *moves += move_player(map, key);
    for (int i = 0; base[i] != NULL; i++) {
        for (int j = 0; base[i][j] != '\0'; j++) {
            current = map[i][j];
            map[i][j] = (base[i][j] == 'O' && current == ' ') ? 'O' : current;
        }
    }
    display_map(map, *moves);
}

static void reset_map(char **map, char **base, unsigned int *moves)
{
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
        map[i] = my_strdup(base[i]);
    }
    *moves = -1;
}

bool sokoban(char **map, char **base)
{
    int key = 0;
    unsigned int moves = 0;

    initscr();
    keypad(stdscr, true);
    start_color();
    init_pair(COLOR_PLAYER, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_BOX, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_STORAGE, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_DEFAULT, COLOR_WHITE, COLOR_BLACK);
    display_map(map, moves);
    while (!is_endgame(map, base)) {
        key = getch();
        if (key == ' ')
            reset_map(map, base, &moves);
        clear();
        if (!map_has_size_for_window(map, getmaxx(stdscr), getmaxy(stdscr)))
            display_resize_term_error();
        else
            play(map, base, key, &moves);
        refresh();
    }
    clear();
    endwin();
    return (all_boxes_on_storage(map, base));
}
