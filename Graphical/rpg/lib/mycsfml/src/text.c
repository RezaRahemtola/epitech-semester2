/*
** EPITECH PROJECT, 2021
** CSFML Utils
** File description:
** Text
*/

#include "mycsfml_text.h"

text_t *text_create(const char *string, const char *font_path, sfColor color,
unsigned int char_size)
{
    text_t *my_text = malloc(sizeof(text_t));
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(font_path);

    if (text == NULL)
        return (NULL);
    if (font == NULL)
        return (NULL);
    sfText_setFont(text, font);
    sfText_setString(text, string);
    sfText_setFillColor(text, color);
    sfText_setCharacterSize(text, char_size);
    my_text->text = text;
    my_text->font = font;
    return (my_text);
}

void text_destroy(text_t *obj)
{
    sfFont_destroy(obj->font);
    sfText_destroy(obj->text);
    free(obj);
}
