/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** score
*/

#ifndef SCORE_H_
    #define SCORE_H_

typedef struct score_s {
    size_t first_place;
    size_t second_place;
    size_t third_place;
    size_t current_score;
} score_t;

score_t *init_score(size_t current);

void print_result(size_t current, int key_quit);
void stock_score(score_t *score);

size_t get_score(int pos);
void get_new_ranking(score_t *score);

char *int_to_str(size_t nb);

#endif /* !SCORE_H_ */
