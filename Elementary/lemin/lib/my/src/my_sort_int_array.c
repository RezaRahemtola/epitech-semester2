/*
** EPITECH PROJECT, 2021
** MY_SORT_INT_ARRAY
** File description:
** Task06
*/

void my_sort_int_array(int *array, int size)
{
    int current = 0;
    int min_pos = 0;
    int temp = 0;

    while (current < size) {
        for (int i = current; i < size; i++)
            min_pos = (array[i] < array[min_pos]) ? i : min_pos;
        temp = array[min_pos];
        array[min_pos] = array[current];
        array[current] = temp;
        current++;
        min_pos = current;
    }
}
