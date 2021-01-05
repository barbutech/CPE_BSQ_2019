/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** same copy but with n
*/

#include <stdlib.h>

char *my_strncpy(char *dest , char const *src, int n)
{
    int i = 0;
    int size;

    while (src[i] != '\0')
        i++;
    size = i;
    dest = malloc(sizeof(char) * (size));
    for (i = 0; i < n; i = i + 1) {
        dest[i] = src[i];
    }
    return (dest);
}