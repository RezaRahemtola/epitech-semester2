/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Main file
*/

#include <stddef.h>
#include "main_menu.h"
#include "my.h"
#include "rpg.h"

int main(int argc, char const *argv[], char **env)
{
    game_t game;

    (void) argc;
    (void) argv;
    if (env == NULL || env[0] == NULL) {
        my_dprintf(2, "Error: No environment\n");
        return (EXIT_ERROR);
    }
    if (!init_game(&game)) {
        my_dprintf(2, "Error: Failed to initialize game\n");
        return (EXIT_ERROR);
    }
    main_menu(&game);
    destroy_game_content(&game);
    return (EXIT_SUCCESS);
}
