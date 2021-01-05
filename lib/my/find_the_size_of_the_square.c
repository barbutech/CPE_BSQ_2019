/*
** EPITECH PROJECT, 2019
** size_of_the_square
** File description:
** find the size of a square
*/

int find_the_size_of_the_square(char *map, int count, \
    int size_of_a_line, int size_max)
{
    for (int i = 0; i < size_max; i++) {
        for (int j = 0; j < size_max; j++) {
            if (map[count + j + i * size_of_a_line] != '.')
                return (0);
        }
    }
    return (1);
}