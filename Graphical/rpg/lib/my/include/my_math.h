/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Math module header
*/

#pragma once

#include <stdbool.h>

int my_nbrlen(int nbr);
int my_lnbrlen(long lnbr);
int my_getnbr(char const *str);
char *my_parsenbr(int nbr);
char *my_parsenbr_base(int nbr, char const *base);
char *my_parsenbr_long(long long lnbr);
char *my_parsenbr(int);
char *my_parsenbr_base(int, char const *);
char *my_parsenbr_long(long long);

int my_llog(long lnbr, int log);
