/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** String module header
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

int my_strlen(char const *str);
char *my_strdup(char const *str);

int my_strcmp(char const *str1, char const *str2);

bool my_str_contains(char const *str, char const *pattern);
bool my_str_starts(char const *str, char const *pattern);

char *my_strcpy(char *, char const *);
char *my_strndup(char const *str, size_t n);
char *my_strncpy(char *, char const *, int);
char *my_strrep(char *, char const *, char const *);
char **my_strsplit(char const *, char);
char *my_substr(char const *, int, int);
char *my_substr_size(char const *, int, int, int);
void my_strfill(char *, int, char);

char *my_strchr(char *str, char c);
