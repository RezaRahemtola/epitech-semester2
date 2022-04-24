/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** Functions to parse redirections
*/

#include "minishell.h"
#include "my.h"

static char *get_next_word(command_t *command, int i)
{
    char *str = command->str;
    char **array = NULL;
    char *word = NULL;

    for (; str[i] == ' ' || str[i] == '\t'; ++i);
    array = str_to_word_array(&str[i]);
    if (array == NULL)
        return (NULL);
    word = my_strdup(array[0]);
    for (int j = i; j < i + my_strlen(word); j++)
        command->str[j] = ' ';
    my_free_2d_array(array);
    return (word);
}

redir_t *get_input_redir(command_t *command)
{
    char *str = command->str;
    int i = 0;
    char *word = NULL;
    int type = NO_IN;

    for (; str[i] != '<' && str[i] != '\0'; ++i);
    if (str[i] == '<') {
        type = (str[i + 1] == '<') ? DOUBLE_IN : SIMPLE_IN;
        command->str[i] = ' ';
        if (type == DOUBLE_IN)
            command->str[++i] = ' ';
        word = get_next_word(command, i);
    }
    return init_redir(word, type);
}

redir_t *get_output_redir(command_t *command)
{
    char *str = command->str;
    int i = 0;
    char *word = NULL;
    int type = NO_OUT;

    for (; str[i] != '>' && str[i] != '\0'; ++i);
    if (str[i] == '>') {
        type = (str[i + 1] == '>') ? DOUBLE_OUT : SIMPLE_OUT;
        command->str[i] = ' ';
        if (type == DOUBLE_OUT)
            command->str[++i] = ' ';
        word = get_next_word(command, i);
    }
    return init_redir(word, type);
}
