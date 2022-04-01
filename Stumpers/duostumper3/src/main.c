/*
** EPITECH PROJECT, 2022
** duostumper3
** File description:
** Main function
*/

#include <stddef.h>
#include "cesar.h"
#include "my_strings.h"

static void display_help(void)
{
    my_putstr("USAGE:\n./cesar -f filename\nOR\n./cesar -s 'string' key\n");
    my_putstr("DESCRIPTION:\nfilename  path of the file to encrypt\n");
    my_putstr("string    string to encrypt\n");
}

int main(int argc, char **argv, char **env)
{
    if (env == NULL || env[0] == NULL) {
        my_puterror("Environnement is not set\n");
        return 84;
    }
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        display_help();
        return (0);
    }
    if (is_error(argc, argv))
        return (84);
    return (cesar(argv));
}
