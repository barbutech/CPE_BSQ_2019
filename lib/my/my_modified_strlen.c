/*
** EPITECH PROJECT, 2019
** my_modified_strlen
** File description:
** find the size of a string with \n
*/

int my_modified_strlen(char * str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}