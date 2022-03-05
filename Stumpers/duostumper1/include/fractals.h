/*
** EPITECH PROJECT, 2022
** duostumper1
** File description:
** Header file
*/

#ifndef FRACTALS
    #define FRACTALS
    #include <stdbool.h>

// Error handling
int error_handling(int argc, char **argv);

// Edge cases
bool edge_cases(char *nb, char *pattern1, char *pattern2);

// Fractals utils
char **calc_next(char **pattern, char **precedent, char **points);
char **new_points(char **actual, int len);

//Main
void fractals(int nb, char *pattern, char *arg_points);

#endif /* !DUOSTUMPER */
