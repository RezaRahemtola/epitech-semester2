/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** stock_score
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "score.h"
#include "my.h"

void get_new_ranking(score_t *score)
{
    size_t tmp = 0;

    if (score->first_place < score->current_score) {
        tmp = score->first_place;
        score->first_place = score->current_score;
        score->third_place = score->second_place;
        score->second_place = tmp;
        return;
    }
    if (score->second_place < score->current_score) {
        tmp = score->second_place;
        score->second_place = score->current_score;
        score->third_place = tmp;
        return;
    }
    if (score->third_place < score->current_score) {
        score->third_place = score->current_score;
        return;
    }
}

void stock_score(score_t *score)
{
    int fd = open(".score", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
    char *first = int_to_str(score->first_place);
    char *second = int_to_str(score->second_place);
    char *third = int_to_str(score->third_place);
    char *result = my_stringf("%s\n%s\n%s", first, second, third);

    if (fd == -1)
        return;
    write(fd, result, my_strlen(result));
    free(result);
    free(first);
    free(second);
    free(third);
}
