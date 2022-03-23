/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** main.c
*/

#include <stdbool.h>
#include <stdio.h>
#include "defender.h"

static void disp_help(void)
{
    my_putstr("A tower defense game created with CSFML.\nUSAGE\n./my_defender"
    " map.txt\n\nDESCRIPTION\nmap.txt\tA file containing lines of the same "
    "length with 'B' for building menu background (better used in the first "
    "lines where the menu is displayed), '.' for basic floor tiles, "
    "'S' for the spawning point, 'E' for the end portal and several characters"
    "for the path depending on the direction to take: '|' for down, '/' for up"
    ", '\' for left and '-' for right. The spawn 'S' is considered as a down "
    "direction.\n\nINTERACTION\nR\tEnable/disable towers range display\n"
    "OPTIONS\n-h\tprint the usage and quit.\n");
}

static bool init_random(void)
{
    unsigned int seed;
    FILE *file = fopen("/dev/urandom", "r");

    if (fread(&seed, sizeof(seed), 1, file) == 1) {
        fclose(file);
        srand(seed);
        return (true);
    }
    fclose(file);
    return (false);
}

int main(int argc, char **argv, char **env)
{
    if (env == NULL || env[0] == NULL)
        return (84);
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        disp_help();
        return (0);
    }
    if (check_errors(argc, argv))
        return (84);
    if (!init_random()) {
        my_puterror("Error: Cannot init random\n");
        return (84);
    }
    defender(argv[1]);
    return (0);
}
