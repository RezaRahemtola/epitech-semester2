/*
** EPITECH PROJECT, 2022
** SoloStumper
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void hidenp(char *needle, char *haystack);

Test(hidenp, matching_example, .init=cr_redirect_stdout)
{
    hidenp("padinton", "paqefwtdjetyiytjneytjoeyjnejeyj");
    cr_assert_stdout_eq_str("1\n");
}

Test(hidenp, unmatched_example, .init=cr_redirect_stdout)
{
    hidenp("ddf6vewg64f", "gtwthgdwthdwfteewhrtag6h4ffdhsd");
    cr_assert_stdout_eq_str("0\n");
}
