/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Audio.h
*/

#pragma once

#include <SFML/Audio.h>

typedef struct sound {
    char *path;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} sound_t;

sound_t *sound_create(char *path, sfBool looping, sfBool play_now);
void sound_destroy(sound_t *obj);
