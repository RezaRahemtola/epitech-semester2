/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Data utilities header file
*/

#pragma once

#include <stdbool.h>
#include <stddef.h>

void *load_data(char const *filepath, size_t data_size);
bool save_data(char const *filepath, void *data, size_t data_size);
