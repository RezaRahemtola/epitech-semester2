/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** Header
*/

#ifndef LIBLIST_H
    #define LIBLIST_H
    #include <stdbool.h>
    #include <stddef.h>

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t;

// Add
void mylist_append(void *data, list_t **dest);

// Destroy
void mylist_destroy(list_t *list, bool free_data, void (*fptr)(void *data));

#endif /* !LIBLIST_H */
