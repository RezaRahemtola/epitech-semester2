/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Particle motion functions
*/

#include "particles.h"

void apply_float_offset(float *value, float offset)
{
    float random_offset = (float) rand() / (float) (RAND_MAX / offset);

    *value += rand() > (RAND_MAX / 2) ? random_offset : -random_offset;
}

void apply_int_offset(int *value, int offset)
{
    int random_offset = rand() / (RAND_MAX / offset);

    *value += rand() > (RAND_MAX / 2) ? random_offset : -random_offset;
}

void apply_sfuint8_offset(sfUint8 *value, sfUint8 offset)
{
    *value += (sfUint8) rand() / (sfUint8) (RAND_MAX / offset);
}

void apply_sfvector2f_offset(sfVector2f *value, sfVector2f *offset)
{
    apply_float_offset(&value->x, offset->x);
    apply_float_offset(&value->y, offset->y);
}
