/*
** EPITECH PROJECT, 2022
** solostumper3
** File description:
** fizzbuzz.c
*/

#include <stdio.h>

void fizzbuzz(int a, int b)
{
    for (; a < b + 1; a++) {
        if (a % 3 == 0)
            printf("Fizz");
        if (a % 5 == 0)
            printf("Buzz");
        if (a % 3 != 0 && a % 5 != 0)
            printf("%d", a);
        printf("\n");
    }
}
