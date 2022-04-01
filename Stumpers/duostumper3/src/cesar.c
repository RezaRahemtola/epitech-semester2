/*
** EPITECH PROJECT, 2022
** cesar
** File description:
** Core function
*/

#include <stdlib.h>
#include "cesar.h"

int cesar(char **argv)
{
    char *buffer = get_buffer(argv[1], argv[2]);
    char *shifted = NULL;
    int key = atoi(argv[3]) % 25;
    int output = 0;

    if (buffer == NULL)
        return 84;
    shifted = shift_string(buffer, key);
    if (shifted == NULL) {
        free(buffer);
        return 84;
    }
    if (!write_in_crypt(shifted))
        output = 84;
    free(shifted);
    free(buffer);
    return output;
}
