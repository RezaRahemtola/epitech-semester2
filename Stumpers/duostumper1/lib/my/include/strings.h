/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Strings.h
*/

#ifndef LIBMY_STRINGS_H
    #define LIBMY_STRINGS_H

// Len
int my_strlen(const char *str);

// Concat
char *my_strcat(char *dest, char *src, bool free_src);
char *my_strncat(char *dest, char *src, int nb, bool free_src);
char *my_newstrcat(char *str1, char *str2, bool free1, bool free2);

// Put
void my_putchar(char c);
void my_putstr(const char *str);
void my_puterror(const char *str);

// Check
bool my_char_isalpha(char c);
bool my_str_isalpha(const char *str);
bool my_char_isnum(char c);
bool my_str_isnum(char const *str);
bool my_str_isalphanum(const char *str);
bool my_str_islower(const char *str);
bool my_str_isupper(char const *str);
bool my_str_isprintable(const char *str);
bool my_charinstr(char c, const char *str);

// Compare
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int n);
int my_strcount(const char *str, const char *pattern);

// Copy
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, int n);
char *my_strdup(char const *src);

// Transform
char *my_strlowcase(char *str);
char *my_strupcase(char *str);
char *my_revstr(char *str);
char *my_strcapitalize(char *str);

// Replace
char *my_streplace(char *src, const char *old, char *new_p);

// Memory
char *my_str_fill(char *str, char c);
char *my_str_allocfill(int nb_char, char c);

#endif /* !LIBMY_STRINGS_H */
