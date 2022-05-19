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
void my_putchar(char c);
void my_putstr(const char *str);
void my_puterror(const char *str);

// Check
bool my_charinstr(char c, const char *str);

// Copy
char *my_strncpy(char *dest, const char *src, int n);

// Memory
char *my_str_allocfill(int nb_char, char c);

// Split
char **my_strsplit(char *str, char delim);

#endif /* !LIBMY_STRINGS_H */
