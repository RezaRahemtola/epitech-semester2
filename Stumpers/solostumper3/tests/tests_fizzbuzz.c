/*
** EPITECH PROJECT, 2022
** SoloStumper
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void fizzbuzz(int a, int b);

Test(fizzbuzz, subject_example, .init=cr_redirect_stdout)
{
    fizzbuzz(10, 15);
    //cr_assert_stdout_eq_str("Buzz\n11\nFizz\n13\n14\nFizzBuzz\n");
}
