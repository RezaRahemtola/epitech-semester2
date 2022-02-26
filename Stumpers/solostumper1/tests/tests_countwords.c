/*
** EPITECH PROJECT, 2022
** SoloStumper
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "countwords.h"

Test(countwords, no_str, .init=cr_redirect_stdout)
{
    countwords("");
}

Test(countwords, repetitive_patterns, .init=cr_redirect_stdout)
{
    countwords("\tNever gonna give you up Never gonna let you down");
    //cr_expect_stdout_eq_str("Never: 2\ngonna: 2\ngive: 1\nyou: 2\nup: 1\nlet: 1\ndown: 1\n");
}

Test(countwords, begin_spaces, .init=cr_redirect_stdout)
{
    countwords("   EZ      \t  win    ");
}
