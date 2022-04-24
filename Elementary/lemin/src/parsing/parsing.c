/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Parsing
*/

#include <unistd.h>
#include <stdlib.h>
#include "parsing.h"
#include "my.h"

static void acquire_nb_ants(lemin_t *lemin, char ***lines)
{
    char **array = *lines;

    if (array == NULL || array[0] == NULL)
        return;
    if (!my_char_isnum(array[0][0]))
        return;
    lemin->nb_ants = my_getnbr(array[0]);
    remove_first_line(lines);
}

static char *get_buffer(void)
{
    char *buffer = NULL;
    char c = '\0';
    size_t size = 0;
    ssize_t read_size = 1;

    while (read_size > 0) {
        size += read_size;
        buffer = my_realloc(buffer, size);
        read_size = read(0, &c, read_size);
        buffer[size - 1] = c;
    }
    if (buffer != NULL)
        buffer[size - 1] = '\0';
    return (buffer);
}

lemin_t *parsing(void)
{
    char *buffer = get_buffer();
    char **lines = my_strsplit(buffer, '\n');
    char *tunnels_output = NULL;
    lemin_t *result = NULL;

    if (buffer == NULL || lines == NULL)
        return (NULL);
    remove_comments(lines);
    result = init_lemin();
    acquire_nb_ants(result, &lines);
    acquire_rooms(result, &lines);
    tunnels_output = acquire_tunnels(result, &lines);
    display_parsing(result, tunnels_output);
    free(tunnels_output);
    free(buffer);
    return (result);
}
