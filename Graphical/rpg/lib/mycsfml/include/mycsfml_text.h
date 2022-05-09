/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Text.h
*/

#pragma once

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <stdlib.h>

typedef struct text {
    sfText *text;
    sfFont *font;
} text_t;

text_t *text_create(const char *string, const char *font_path, sfColor color,
unsigned int char_size);
void text_destroy(text_t *obj);
