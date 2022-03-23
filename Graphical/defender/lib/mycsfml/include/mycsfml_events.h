/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** .h
*/

#ifndef MYCSFML_EVENTS_H_
    #define MYCSFML_EVENTS_H_
    #include <SFML/Graphics.h>

void check_closing_event(sfRenderWindow *window, sfEvent event);
sfBool is_click_on_sprite(sfEvent *event, sfSprite *sprite);

#endif /* !MYCSFML_EVENTS_H_ */
