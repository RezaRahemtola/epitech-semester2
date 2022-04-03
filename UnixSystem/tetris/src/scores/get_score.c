/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** score
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "score.h"
#include "my.h"

static int my_countline(char *str, int line)
{
    int count = 0;

    if (line < 1)
        return (0);
    for (int i = 0; i < line; i++, count++) {
        for (; str[count] != '\0' && str[count] != '\n'; count++);
    }
    return (count - 1);
}

static char *read_file(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat sb;
    char *buffer = NULL;

    if (fd == -1 || stat(file, &sb) == -1)
        return (NULL);
    buffer = my_str_allocfill(sizeof(char) * (sb.st_size + 1), '\0');
    if (buffer == NULL)
        return (NULL);
    if (read(fd, buffer, sb.st_size) == -1)
        return (NULL);
    close(fd);
    return (buffer);
}

size_t get_score(int pos)
{
    size_t nb = 0;
    int start_of_line = 0;
    char *file = read_file(".score");

    if (file == NULL)
        return (0);
    start_of_line = my_countline(file, pos - 1);
    if (pos != 1)
        start_of_line += 1;
    nb = my_getnbr(&file[start_of_line]);
    return (nb);
}

score_t *init_score(size_t current)
{
    score_t *score = malloc(sizeof(score_t));

    score->current_score = current;
    score->first_place = get_score(1);
    score->second_place = get_score(2);
    score->third_place = get_score(3);
    return (score);
}
