/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Header file
*/

#ifndef DEFENDER_H
    #define DEFENDER_H

    #include "my.h"
    #include "mycsfml_all.h"

    #define MIN(x, y) (x < y ? x : y)
    #define MAX(x, y) (x < y ? y : x)

    #define WIDTH 1920
    #define HEIGHT 1080
    #define CHAR_UP '/'
    #define CHAR_DOWN '|'
    #define CHAR_LEFT '\\'
    #define CHAR_RIGHT '-'
    #define CHAR_FLOOR '.'
    #define CHAR_BUILD_BG 'B'
    #define CHAR_SPAWN 'S'
    #define CHAR_END 'E'

typedef enum {
    BUTTON_PLAY,
    BUTTON_EXIT,
    BUTTON_RESUME,
    BUTTON_START_MENU,
    BUTTON_HOW_PLAY,
} menu_buttons_t;

typedef enum {
    SINGLE_DMG,
    ZONE_DMG,
    SLOW,
    MID
} tower_damage_t;

typedef struct enemy_type_s {
    sfTexture *texture;
    int health;
    int damage;
    int speed;
} enemy_type_t;

typedef struct enemy_s {
    enemy_type_t *type;
    sfSprite *sprite;
    sfVector2f *pos;
    sfVector2f *dir;
    sfClock *clock;
    int health;
    int speed;
    struct enemy_s *next;
} enemy_t;

typedef struct tower_type_s {
    sfTexture *texture;
    int dmg_type;
    int damage;
    int cost;
    int range;
    int speed;
} tower_type_t;

typedef struct tower_s {
    tower_type_t *type;
    sfSprite *sprite;
    sfCircleShape *range;
    sfVector2f *pos;
    sfClock *clock;
    sfClock *shot;
    struct tower_s *next;
} tower_t;

typedef struct info_s {
    char **map;
    sfVector2f *spawn;
    sfVector2f *end;
    sfVector2f *scale;
    sfSprite ***squares;
    tower_type_t **tower_types;
    enemy_type_t **enemy_types;
} info_t;

// Game
typedef struct game_s {
    int hp;
    int gold;
    int kills;
    int spent;
    tower_t *towers;
    enemy_t *enemies;
    sfClock *wave;
    int next;
    sound_t *death_sound;
    info_t *info;
    bool display_range;
} game_t;

game_t *init_game(info_t *info);
void free_game(game_t *game);

// Textures
typedef struct textures_s {
    sfTexture *path;
    sfTexture *floor;
    sfTexture *spawn;
    sfTexture *end;
    sfTexture *build_bg;
    sfTexture *play;
    sfTexture *resume;
    sfTexture *exit;
    sfTexture *how_play;
    sfTexture *buy_fire;
    sfTexture *buy_ice;
    sfTexture *buy_poison;
    sfTexture *buy_mid;
    sfTexture *gold;
    sfTexture *kill;
    sfTexture *health;
} textures_t;

textures_t *load_textures(void);
void free_textures(textures_t *list);

// Building
typedef struct building_s {
    sfBool is_dragged;
    sfSprite *buy_fire;
    sfSprite *buy_ice;
    sfSprite *buy_poison;
    sfSprite *buy_mid;
    sfSprite *dragged_sprite;
    sfSprite *gold;
    sfSprite *kill;
    sfSprite *health;
    sound_t *button_sound;
} building_t;

building_t *init_building(textures_t *textures);
void free_building(building_t *building);
void check_building_menu_click(sfEvent *event, building_t *building,
info_t *info, game_t *game);
void display_building(building_t *building, sfRenderWindow *window, game_t *);

// Core functions
void defender(char *filepath);
void start_menu(info_t *info, sfRenderWindow *window, textures_t *textures);
void play(info_t *info, sfRenderWindow *window, textures_t *textures);
bool pause_menu(sfRenderWindow *window);

// Map
char **load_map_from_file(char *filepath);
sfVector2f *find_spawn(char **map);
sfVector2f *find_end(char **map);
sfSprite ***generate_map(char **map, textures_t *list);
void display_map(sfRenderWindow *window, char **map, sfSprite ***sprites);
void free_map_sprites(sfSprite ***sprites, char **map);

// Towers
void create_tower(sfVector2f *vector, const sfTexture *texture,
game_t *game, info_t *info);
void display_towers(sfRenderWindow *window, game_t *game);
void add_tower(tower_t **list, tower_t *tower);
void clear_towers(tower_t *towers);
void update_towers(game_t *game);
tower_t *find_tower(tower_t *list, int x, int y);

// Enemies
float get_distance(sfVector2f *vec1, sfVector2f *vec2);
void display_enemies(sfRenderWindow *window, enemy_t *enemies);
void add_enemy(enemy_t **list, enemy_t *enemy);
void remove_enemy(enemy_t **list, enemy_t *enemy);
void clear_enemies(enemy_t *enemies);
void update_enemies(game_t *game, info_t *info);
void update_direction(enemy_t *enemy, game_t *game, info_t *info);
void shoot_enemy(game_t *game, enemy_t *enemy, tower_t *tower);

// Healthbar
void display_healthbar(enemy_t *current, sfSprite *healthbar,
sfSprite *background, sfRenderWindow *window);

// Types
void generate_types(info_t *info);
void free_types(info_t *info);
tower_type_t *find_type(const sfTexture *texture, info_t *info);

// Events
buttons_t *handle_menu_events(sfRenderWindow *window, buttons_t *buttons);
bool handle_key_event(sfRenderWindow *window);

// Error handling
bool check_errors(int argc, char **argv);

#endif /* !DEFENDER_H */
