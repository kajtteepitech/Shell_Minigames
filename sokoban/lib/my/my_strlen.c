/*
** PROJECT, 2020
** my_strlen
** File description:
** returns the length of a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}