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
void obj_destroy(list_t *obj, bool free_data, void (*fptr)(void *data));
void mylist_destroy(list_t *list, bool free_data, void (*fptr)(void *data));

// Len
int mylist_len(list_t *list);

// Convert
char **mylist_to_array(list_t *list, char *(*fptr)(const char *str));
list_t *array_to_mylist(char **array, char *(*fptr)(const char *str));

#endif /* !LIBLIST_H */
