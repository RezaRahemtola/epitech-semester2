/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** error handling
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"

static bool check_map_content(char *buffer)
{
    int player_count = my_strcount(buffer, "P");
    int box_count = my_strcount(buffer, "X");
    int storage_count = my_strcount(buffer, "O");

    if (player_count != 1)
        return (false);
    if (box_count != storage_count)
        return (false);
    return (true);
}

static bool check_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    char *buffer = NULL;
    bool invalid_map = false;

    if (fd == -1)
        return (true);
    if (stat(filepath, &sb) == -1)
        return (true);
    buffer = my_str_allocfill(sizeof(char) * (sb.st_size + 1), '\0');
    read(fd, buffer, sb.st_size);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (!my_charinstr(buffer[i], " #XOP\n"))
            invalid_map = true;
    }
    if (!check_map_content(buffer))
        invalid_map = true;
    free(buffer);
    close(fd);
    return (invalid_map);
}

bool check_errors(int argc, char **argv)
{
    if (argc != 2)
        return (true);
    if (check_file(argv[1]))
        return (true);
    return (false);
}
