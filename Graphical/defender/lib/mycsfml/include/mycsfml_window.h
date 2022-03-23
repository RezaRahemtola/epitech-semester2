/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Window.h
*/

#ifndef MYCSFML_WINDOW_H_
    #define MYCSFML_WINDOW_H_
    #include <SFML/Graphics.h>

sfRenderWindow *create_window(unsigned int width, unsigned int height,
char const *title, unsigned int framerate);

#endif /* !MYCSFML_WINDOW_H_ */
