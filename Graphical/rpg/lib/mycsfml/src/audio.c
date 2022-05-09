/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Audio and sound functions
*/

#include <stdlib.h>
#include "mycsfml_audio.h"

sound_t *sound_create(char *path, sfBool looping, sfBool play_now)
{
    sound_t *my_sound = malloc(sizeof(sound_t));

    if (my_sound == NULL)
        return (NULL);
    my_sound->sound = sfSound_create();
    my_sound->sound_buffer = sfSoundBuffer_createFromFile(path);
    if (my_sound->sound_buffer == NULL)
        return (NULL);
    my_sound->path = path;
    sfSound_setBuffer(my_sound->sound, my_sound->sound_buffer);
    sfSound_setLoop(my_sound->sound, looping);
    if (play_now)
        sfSound_play(my_sound->sound);
    return (my_sound);
}

void sound_destroy(sound_t *obj)
{
    sfSound_destroy(obj->sound);
    sfSoundBuffer_destroy(obj->sound_buffer);
    free(obj);
}
