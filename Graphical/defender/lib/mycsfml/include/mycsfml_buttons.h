/*
** EPITECH PROJECT, 2022
** CSFML utils
** File description:
** Header file
*/

#ifndef MYCSFML_BUTTONS
    #define MYCSFML_BUTTONS
    #include <SFML/Graphics.h>

typedef struct buttons_s {
    int type;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    struct buttons_s *next;
} buttons_t;

void change_buttons_state(buttons_t *button, sfEvent *event,
sfRenderWindow *window);
buttons_t *create_button(sfTexture *texture, sfVector2f pos, int type);
buttons_t *get_clicked_button(buttons_t *buttons, sfEvent *event);
void display_buttons(buttons_t *list, sfRenderWindow *window);
void destroy_buttons(buttons_t *head, sfBool destroy_texture);

#endif /* !MYCSFML_BUTTONS */
