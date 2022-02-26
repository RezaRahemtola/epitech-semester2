/*
** EPITECH PROJECT, 2022
** SoloStumper
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void geek_name_formatter(char *str);

Test(geek_name_formatter, subject_example, .init=cr_redirect_stdout)
{
    geek_name_formatter("santa Tomato!KETCHUP/");
    cr_assert_stdout_eq_str("S4Nt4 T0M4T0!k3tCh2p/\n");
}

Test(geek_name_formatter, subject_reversed_with_curly, .init=cr_redirect_stdout)
{
    geek_name_formatter("SANTA tOMATO!ketchup/{}");
    cr_assert_stdout_eq_str("S4Nt4 T0M4T0!k3tCh2p/{}\n");
}

Test(geek_name_formatter, full_special, .init=cr_redirect_stdout)
{
    geek_name_formatter("oOiIuUeEaAyY");
    cr_assert_stdout_eq_str("001122334455\n");
}
