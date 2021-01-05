/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq program
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

int find_the_error(int ac, char *filepath)
{
    int fd;
    char buff[1];
    if (ac > 2 || ac < 2)
        return (84);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    if (read(fd, buff, 1) == -1)
        return (84);
    return (fd);
}

char *copy_the_map(char *file, int fd)
{
    struct stat size;
    char *map;
    int size_of_file;
    char buffer[1];
    int count = 0;

    stat(file, &size);
    map = malloc(size.st_size);
    size_of_file = my_strlen(map) - 1;
    while (buffer[0] != '\n')
        read(fd, buffer, 1);
    read(fd, map, size.st_size - count);
    return (map);
}

void print_this_square(char *map, int size_max, int coord)
{
    int size_of_a_line = my_modified_strlen(map) + 1;

    for (int i = 0; i < size_max -1; i++) {
        for (int j = 0; j < size_max - 1; j++) {
            map[coord + j + i * size_of_a_line] = 'x';
        }
    }
}

int my_bsq(int fd, char *file)
{
    char *map = copy_the_map(file, fd);
    int coord = 0;
    int size_of_a_line = my_modified_strlen(map) + 1;
    int count = 0;
    int size_max;

    while (map[count] != '\0') {
            while (find_the_size_of_the_square(map, count, \
                 size_of_a_line, size_max) == 1) {
                size_max++;
                coord = count;
            }
        count++;
    }
    print_this_square(map, size_max, coord);
    write(1, map, my_strlen(map));
    close (fd);
    return (1);
}

int main(int argc, char *argv[])
{
    int fd = find_the_error(argc, argv[1]);

    if (fd == 84)
        return (84);
    my_bsq(fd, argv[1]);
    return 0;
}
