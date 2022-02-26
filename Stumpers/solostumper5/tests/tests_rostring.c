/*
** EPITECH PROJECT, 2022
** SoloStumper
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void rostring(char *str);

Test(rostring, subject_example_one, .init=cr_redirect_stdout)
{
    rostring("abc   ");
    cr_assert_stdout_eq_str("abc\n");
}

Test(rostring, subject_example_two, .init=cr_redirect_stdout)
{
    rostring("Let there    be more light");
    cr_assert_stdout_eq_str("there be more light Let\n");
}

Test(rostring, subject_example_three, .init=cr_redirect_stdout)
{
    rostring("\tAkjhZ \tzLKIJz , 23y");
    cr_assert_stdout_eq_str("zLKIJz , 23y AkjhZ\n");
}

Test(rostring, one_word, .init=cr_redirect_stdout)
{
    rostring("abc");
    cr_assert_stdout_eq_str("abc\n");
}

Test(rostring, one_word_with_tab, .init=cr_redirect_stdout)
{
    rostring("abc\t");
    cr_assert_stdout_eq_str("abc\n");
}

Test(rostring, word_ending_with_tab, .init=cr_redirect_stdout)
{
    rostring("Let\tthere    be more\tlight");
    cr_assert_stdout_eq_str("there be more light Let\n");
}
