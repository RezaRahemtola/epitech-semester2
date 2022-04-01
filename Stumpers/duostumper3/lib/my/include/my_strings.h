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
void my_puterror(const char *str);

// Check
bool my_char_isalpha(char c);

// Compare
int my_strcmp(const char *s1, const char *s2);

// Copy
char *my_strcpy(char *dest, const char *src);
char *my_strdup(char const *src);

// Memory
char *my_str_allocfill(int nb_char, char c);

#endif /* !LIBMY_STRINGS_H */
