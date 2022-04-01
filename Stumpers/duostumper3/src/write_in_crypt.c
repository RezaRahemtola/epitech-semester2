/*
** EPITECH PROJECT, 2022
** duo stumper 2
** File description:
** write in crypt
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "my_strings.h"

bool write_in_crypt(char *str)
{
    int fd = open("crypt", O_WRONLY | O_CREAT);

    if (fd == -1) {
        my_puterror("Cannot open/create the output file\n");
        return false;
    }
    if (write(fd, str, strlen(str)) == -1) {
        close(fd);
        my_puterror("Cannot write in the crypt file\n");
        return false;
    }
    if (fchmod(fd, S_IRUSR | S_IRGRP | S_IROTH) == -1) {
        my_puterror("Cannot set crypt permissions to read-only\n");
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
