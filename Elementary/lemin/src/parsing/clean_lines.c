/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** convert_line
*/

#include <stdlib.h>
#include "my_strings.h"

static bool is_command(char *str)
{
    if (my_strncmp(str, "##start", 7) == 0)
        return (true);
    if (my_strncmp(str, "##end", 5) == 0)
        return (true);
    return (false);
}

static char *convert_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (is_command(&line[i]))
            i += 2;
        if (!is_command(&line[i]) && line[i] == '#')
            my_str_fill(&line[i], '\0');
    }
    return (line);
}

static void remove_empty_line(char **lines, int x)
{
    if (lines[x][0] != '\0')
        return;
    for (; lines[x] != NULL; x++) {
        free(lines[x]);
        if (lines[x + 1] == NULL)
            lines[x] = NULL;
        else
            lines[x] = my_strdup(lines[x + 1]);
    }
}

void remove_comments(char **lines)
{
    for (int x = 0; lines[x] != NULL; x++) {
        lines[x] = convert_line(lines[x]);
        for (int i = my_strlen(lines[x]); i >= 0 && lines[x][i] == ' '; i--)
            lines[x][i] = '\0';
        remove_empty_line(lines, x);
    }
}
