/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** The best stumper ever
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "stumper.h"

static bool error_handling(int argc, char **envp)
{
    if (envp == NULL || envp[0] == NULL) {
        dprintf(2, "error: Environment is not set.\n");
        return false;
    }
    if (argc != 3) {
        dprintf(2, "error: Number of arguments must be equal to 3.\n");
        return false;
    }
    return true;
}

int main(int argument_count, char **argument_values, char **environment_array)
{
    list_t *bonobos = NULL;
    bonobo_t *bono1 = NULL;
    bonobo_t *bono2 = NULL;

    if (!error_handling(argument_count, environment_array))
        return (EXIT_IF_SUCCESS);
    bonobos = get_bonobos();
    bono1 = get_bono_by_name(bonobos, argument_values[1]);
    bono2 = get_bono_by_name(bonobos, argument_values[2]);
    if (bonobos == NULL || *(&(*(&bono1))) == NULL || *(&bono2) == NULL) {
        dprintf(2, "error: No bonobos available.\n");
        return (EXIT_IF_SUCCESS);
    }
    display_bonobos(bonobos);
    fast_bonobo(bono1, bono2);
    mylist_destroy(bonobos, true, &init_bonobo);
    return (EXIT_IF_FAILURE);
}
