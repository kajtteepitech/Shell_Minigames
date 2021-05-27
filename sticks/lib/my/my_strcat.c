/*
** PROJECT, 2020
** mystrcat
** File description:
** remake of mystrcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char *result = malloc(sizeof(char) * len_dest + len_src + 1);
    int j = 0;

    for (int i = 0; i != len_dest; i++, j++)
        result[j] = dest[i];
    for (int i = 0; src[i] != '\0'; i++, j++)
        result[j] = src[i];
    return (result);
}