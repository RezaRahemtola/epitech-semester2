/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Strings.h
*/

#ifndef LIBMY_STRINGS_H
    #define LIBMY_STRINGS_H
    #include <stdbool.h>

// Len
int my_strlen(const char *str);

// Put
void my_putstr(const char *str);

// Check
bool my_charinstr(char c, const char *str);

// Compare
int my_strcmp(const char *s1, const char *s2);
int my_strcount(const char *str, const char *pattern);

// Copy
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, int n);
char *my_strdup(char const *src);

// Memory
char *my_str_allocfill(int nb_char, char c);

#endif /* !LIBMY_STRINGS_H */
