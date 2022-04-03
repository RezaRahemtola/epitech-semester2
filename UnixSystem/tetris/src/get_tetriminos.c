/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Check .tetriminos directory
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include "tetris.h"
#include "my.h"

static bool is_info_error(tetriminos_t *info, char *str)
{
    char **array = my_strsplit(str, '\n');
    char *line = NULL;
    char **line_elems = NULL;
    bool is_error = my_arraylen(array) <= 0;

    if (!is_error) {
        line = array[0];
        line_elems = my_strsplit(line, ' ');
        is_error = (my_arraylen(line_elems) != 3);
    }
    if (!is_error) {
        info->width = my_getnbr(line_elems[0]);
        info->height = my_getnbr(line_elems[1]);
        info->color = my_getnbr(line_elems[2]);
    }
    is_error = (is_error || my_strlen(line_elems[2]) != 1 ||
    (line_elems[2][0] < '0' && line_elems[2][0] > '7')) ? true : false;
    my_free_2d_array(array);
    my_free_2d_array(line_elems);
    return (is_error || info->height == 0 || info->width == 0);
}

static bool check_piece_error(char **piece, int width)
{
    bool has_error = false;

    if (piece == NULL)
        return (true);
    for (int i = 0; piece[i] != NULL && !has_error; i++) {
        for (int j = 0; piece[i][j] != '\0'; j++)
            has_error = !my_charinstr(piece[i][j], " *") ? true : has_error;
        for (int j = my_strlen(piece[i]) - 1; piece[i][j] == ' ' && j > 0; j--)
            piece[i][j] = '\0';
        if (my_strlen(piece[i]) > width || my_strcount(piece[i], "*") < 1)
            has_error = true;
    }
    if (my_array_biggest_len(piece) != width)
        has_error = true;
    return (has_error);
}

static char *get_file_content(char *filename, char *dirpath)
{
    char *filepath = my_newstrcat(dirpath, filename, false, false);
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    struct stat sb;

    if (stat(filepath, &sb) == -1)
        return (NULL);
    free(filepath);
    buffer = my_str_allocfill(sb.st_size + 1, '\0');
    if (fd == -1 || read(fd, buffer, sb.st_size) == 0)
        return (NULL);
    close(fd);
    return (buffer);
}

tetriminos_t *get_tetrimino(char *name, char *dirpath)
{
    tetriminos_t *info = init_tetrimino(name);
    char *buffer = get_file_content(name, dirpath);
    int line = 0;

    if (buffer != NULL)
        info->name[my_strlen(info->name) - 10] = '\0';
    if (buffer == NULL || is_info_error(info, buffer)) {
        free(buffer);
        info->has_error = true;
        return (info);
    }
    for (; buffer[line] != '\n' && buffer[line] != '\0'; line++);
    if (buffer[line] != '\0')
        line++;
    info->piece = my_strsplit(&(buffer[line]), '\n');
    info->has_error = check_piece_error(info->piece, info->width);
    if (my_arraylen(info->piece) != info->height)
        info->has_error = true;
    free(buffer);
    return (info);
}

list_t *get_tetriminos(char *dirpath)
{
    DIR *d = opendir(dirpath);
    struct dirent *dir;
    list_t *list = NULL;
    tetriminos_t *tetri = NULL;

    if (d == NULL)
        return (NULL);
    while ((dir = readdir(d)) != NULL) {
        if (my_strstr(dir->d_name, ".tetrimino") != NULL) {
            tetri = get_tetrimino(dir->d_name, dirpath);
            mylist_append(tetri, &list);
        }
    }
    closedir(d);
    return (list);
}
