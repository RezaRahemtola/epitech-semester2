/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_strcapitalize function
*/

static int is_up(char c)
{
    int result = 0;

    if (c > 64 && c < 91) {
        result = 1;
    }
    return (result);
}

static int is_low(char c)
{
    int result = 0;

    if (c > 96 && c < 123) {
        result = 1;
    }
    return (result);
}

static int is_letter(char c)
{
    int result = 1;

    if (is_up(c) || is_low(c) || (c > 47 && c < 58)) {
        result = 0;
    }
    return (result);
}

char *my_strcapitalize(char *str)
{
    int space = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_low(str[i]) && (space == 1 || i == 0)) {
            space = 0;
            str[i] = str[i] - 32;
        } else if (space == 0 && is_up(str[i]) && i > 0) {
            str[i] = str[i] + 32;
        } else {
            space = is_letter(str[i]);
        }
    }
    return (str);
}
