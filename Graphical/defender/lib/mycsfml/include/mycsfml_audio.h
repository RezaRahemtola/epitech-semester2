/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Audio.h
*/

#ifndef MYCSFML_AUDIO_H_
    #define MYCSFML_AUDIO_H_
    #include <SFML/Audio.h>

typedef struct sound_s {
    char *path;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} sound_t;

sound_t *sound_create(char *path, sfBool looping, sfBool play_now);
void sound_destroy(sound_t *obj);

#endif /* !MYCSFML_AUDIO_H_ */
