/*
** EPITECH PROJECT, 2022
** need4steck
** File description:
** End condition
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_arrays.h"
#include "my_string.h"
#include "my.h"
#include "ai.h"

bool is_end_array(char **array)
{
    int size = my_arraylen(array);

    return (my_str_starts(array[size - 2], "Track Cleared") == 0);
}

bool is_end(char *line)
{
    char **array = my_strsplit(line, ':');
    bool end = false;

    if (array == NULL)
        return (false);
    end = is_end_array(array);
    my_free_arrays(1, array);
    return (end);
}

bool send_first_last_instruction(car_t *car)
{
    char *tmp = NULL;
    size_t read = 0;

    dprintf(STDOUT, "WHEELS_DIR:%f\n", car->wheels);
    getline(&tmp, &read, stdin);
    if (is_end(tmp)) {
        free(tmp);
        return (true);
    }
    free(tmp);
    return (false);
}

bool send_first_instructions(car_t *car)
{
    char *tmp = NULL;
    size_t read = 0;

    dprintf(STDOUT, "START_SIMULATION\n");
    getline(&tmp, &read, stdin);
    if (is_end(tmp)) {
        free(tmp);
        return (true);
    }
    dprintf(STDOUT, "CAR_FORWARD:%f\n", car->speed);
    getline(&tmp, &read, stdin);
    if (is_end(tmp)) {
        free(tmp);
        return (true);
    }
    free(tmp);
    return (send_first_last_instruction(car));
}
