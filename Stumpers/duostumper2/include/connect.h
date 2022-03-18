/*
** EPITECH PROJECT, 2022
** duostumper2
** File description:
** Header file
*/

#ifndef CONNECT
    #define CONNECT
    #include <stdbool.h>

// Params
typedef struct param_s {
    int width;
    int height;
    char player_one;
    char player_two;
    char referee;
} param_t;

param_t *init_param(void);
bool handle_options(int argc, char **argv, param_t *param);

// Replace
char **modify_argv(int argc, char **argv);

// Map
char **create_map(int width, int height);
void display_map(char **map);
void place_piece(char piece, char **map, int column);
bool is_map_full(char **map);

// Error handling
bool invalid_option(param_t *param);

// Game
void play(param_t *param);

// Input
int get_input(param_t *param, char player, char **map);

// Win checks
bool check_player_win(char **map, param_t *param, char player);
void edit_map(char **map, int row, int col, char referee);

#endif /* !CONNECT */
