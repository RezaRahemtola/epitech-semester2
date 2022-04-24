/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Functions to display parsing output
*/

#include <stdlib.h>
#include "parsing.h"
#include "my.h"

void display_parsing(lemin_t *lemin, char *tunnels_output)
{
    list_t *list = lemin->rooms;
    room_t *room = NULL;

    my_printf("#number_of_ants\n%d\n#rooms\n", lemin->nb_ants);
    while (list != NULL) {
        room = list->data;
        if (room == lemin->start)
            my_putstr("##start\n");
        if (room == lemin->end)
            my_putstr("##end\n");
        my_printf("%s %d %d\n", room->name, room->x, room->y);
        list = list->next;
    }
    my_putstr("#tunnels\n");
    if (tunnels_output != NULL)
        my_putstr(tunnels_output);
}

void remove_first_line(char ***array)
{
    if (array == NULL || *array == NULL)
        return;
    free((*array)[0]);
    (*array)++;
}

bool is_parsing_incomplete(lemin_t *lemin)
{
    if (lemin->nb_ants == 0) {
        my_puterror("Error: Invalid ants number\n");
        return (true);
    }
    if (lemin->start == NULL || lemin->end == NULL) {
        my_puterror("Error: No start or end room\n");
        return (true);
    }
    if (lemin->rooms == NULL) {
        my_puterror("Error: No rooms\n");
        return (true);
    }
    return (false);
}
