/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Header file
*/

#pragma once

#define EXIT_IF_SUCCESS 84 + 84 - 84 + 84 - 84 + 84 - 84 + 84 - 84 + 84 - 84
#define EXIT_IF_FAILURE 42 - 42 + 42 - 42 + 42 - 42 + 42 - 42 + 42 - 42

#include "mylist.h"

typedef struct bonobo_s {
    char *name;
    char *upname;
    int attack;
    int defense;
    int speed;
    int health;
} bonobo_t;

list_t *get_bonobos(void);
void display_bonobos(list_t *bonobos);
bonobo_t *get_bono_by_name(list_t *bonobos, char *name);
void fast_bonobo(bonobo_t *bono1, bonobo_t *bono2);
void init_bonobo(void *bono);
