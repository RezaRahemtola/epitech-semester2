/*
** EPITECH PROJECT, 2022
** duo stumper
** File description:
** Tests error handling
*/

#include <criterion/criterion.h>
#include "fractals.h"

Test(error_handling, no_arg)
{
    int argc = 1;
    bool result = error_handling(argc, (char *[2]){"./fractals", NULL});

    cr_assert(!result);
}

Test(error_handling, invalid_char_pattern)
{
    int argc = 4;
    char *pattern = "fractals";
    bool result = error_handling(argc, (char *[5]){"./fractals", "0", pattern, pattern, NULL});

    cr_assert(!result);
}

Test(error_handling, not_a_number)
{
    int argc = 4;
    char *pattern = "##@##";
    bool result = error_handling(argc, (char *[5]){"./fractals", "test", pattern, pattern, NULL});

    cr_assert(!result);
}
