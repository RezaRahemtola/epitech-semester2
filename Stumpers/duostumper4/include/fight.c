/*
** EPITECH PROJECT, 2022
** duo stumper 4
** File description:
** fight
*/

#include <stdio.h>
#include <stdlib.h>
#include "stumper.h"

static void who_is_the_alpha_bonobo(bonobo_t *dead, bonobo_t *alive)
{
    printf("%s is KO\n%s wins the fight!\n", dead->name, alive->name);
}

static void fight(bonobo_t *first, bonobo_t *second)
{
    int damage = (first->attack > 0) ? rand() % first->attack : 0;

    printf("%s attacks for %d damage\n", first->name, damage);
    printf("%s blocks %d damage\n", second->name, second->defense);
    if (damage > second->defense)
        second->health -= damage - second->defense;
    printf("%s loses %d health (%d left)\n", second->name,
        (damage > second->defense) ? damage - second->defense : 0,
        (second->health > 0) ? second->health : 0);
    if (first->health <= 0) {
        who_is_the_alpha_bonobo(first, second);
        return;
    }
    if (second->health <= 0) {
        who_is_the_alpha_bonobo(second, first);
        return;
    }
    fight(second, first);
}

void fast_bonobo(bonobo_t *bono1, bonobo_t *bono2)
{
    if (bono1->speed >= bono2->speed)
        fight(bono1, bono2);
    if (bono1->speed < bono2->speed)
        fight(bono2, bono1);
}
