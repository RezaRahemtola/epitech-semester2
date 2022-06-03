/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Functions header
*/

#pragma once

#include <stddef.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define CTOI(x) ((x) - '0')
#define ITOC(x) ((x) + '0')
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

static const char * const BINARY_BASE = "01";
static const char * const OCTAL_BASE = "01234567";
static const char * const HEXA_LOWER_BASE = "0123456789abcdef";
static const char * const HEXA_UPPER_BASE = "0123456789ABCDEF";

void my_putchar(char c);
void my_putstr(char const *str);

int my_dprintf(int fd, char const *format, ...);
char *my_stringf(char const *format, ...);

void my_free(int size, ...);
void my_free_arrays(int size, ...);

void my_memcpy(void *dest, const void *src, size_t size);
void my_memset(void *dest, int c, size_t size);

char *my_strndup(char const *str, size_t n);

void *my_calloc(size_t element_count, size_t element_size);
void *my_reallocarray(void *pointer, size_t count,
    size_t old_count, size_t size);
