/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** Parsing header
*/

#pragma once

// Parsing
char *get_command_path(char *command, list_t *env);
list_t *parse_input(char *buffer, list_t *env);

// Error handling
bool check_parsing_error(list_t *list);
