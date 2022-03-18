/*
** EPITECH PROJECT, 2022
** duo stumper
** File description:
** Utils
*/

void edit_map(char **map, int row, int col, char referee)
{
    col--;
    row--;
    for (int i = 0; i < 4; i++) {
        map[row][col] = referee;
        row--;
        col--;
    }
}
