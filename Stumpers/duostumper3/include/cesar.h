/*
** EPITECH PROJECT, 2022
** duostumper3
** File description:
** Header file
*/

#pragma once

#include <stdbool.h>

// Main function
int cesar(char **argv);

// Load buffer
char *get_buffer(char *option, char *value);

// Encryption
char *shift_string(char *str, int key);

// Error handling
bool is_error(int argc, char **argv);

// Output
bool write_in_crypt(char *str);
