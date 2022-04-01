/*
** EPITECH PROJECT, 2022
** duostumper3
** File description:
** Functions to load the file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_strings.h"

static char *load_buffer_from_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    char *buffer = NULL;

    if (fd == -1) {
        my_puterror("Cannot open input file.\n");
        return (NULL);
    }
    if (stat(filepath, &sb) == -1) {
        my_puterror("Cannot get input file informations.\n");
        return (NULL);
    }
    buffer = my_str_allocfill(sizeof(char) * (sb.st_size + 1), '\0');
    if (buffer == NULL) {
        my_puterror("Cannot allocate memory.\n");
        return (NULL);
    }
    read(fd, buffer, sb.st_size);
    close(fd);
    return (buffer);
}

char *get_buffer(char *option, char *value)
{
    char *buffer = NULL;

    if (my_strcmp(option, "-f") == 0)
        buffer = load_buffer_from_file(value);
    else if (my_strcmp(option, "-s") == 0)
        buffer = my_strdup(value);
    if (buffer == NULL)
        return (NULL);
    return (buffer);
}
