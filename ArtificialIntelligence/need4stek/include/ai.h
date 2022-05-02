/*
** EPITECH PROJECT, 2022
** need4steck
** File description:
** Header
*/

#pragma once

#include <stdbool.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

typedef struct car_s {
    bool end;
    float speed;
    float wheels;
    float *lidar;
} car_t;

// Init
bool init_car(car_t *car);
void destroy_car(car_t *car);

// Core
void ai(void);
void get_info_lidar(car_t *car);

// Instructions
void change_speed(float speed);
void change_direction(float wheels);

// Compute
void compute_speed(car_t *car);
void compute_direction(car_t *car);

// End
bool send_first_instructions(car_t *car);
bool is_end(char *line);
bool is_end_array(char **array);
