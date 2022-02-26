/*
** EPITECH PROJECT, 2022
** SoloStumper1
** File description:
** countwords.h
*/

#ifndef COUNTWORDS_H_
    #define COUNTWORDS_H_

typedef struct pattern_s {
    char *str;
    int nb;
    struct pattern_s *next;
} pattern_t;

// Lib functions
char *my_strdup(char const *src);
char *my_malloc_str(size_t nb_char, char c);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);

// Pattern list functions
void countwords(char *str);
void my_putend(char *str, pattern_t **dest);
void list_destroy(pattern_t *obj);
int is_in_list(char *str, pattern_t *list);
char *get_pattern(char **content);
void increment_pattern_count(int index, pattern_t *list);

#endif /* !COUNTWORDS_H_ */
