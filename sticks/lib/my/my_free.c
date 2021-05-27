/*
** PROJECT, 2021
** my_free
** File description:
** frees stuff
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

void my_free(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}