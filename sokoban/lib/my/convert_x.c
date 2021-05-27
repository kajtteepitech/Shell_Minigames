/*
** PRINTF PROJECT, 2020
** convert_h
** File description:
** converts hexadecimal
*/

#include "my.h"
#include <stdarg.h>

void convert_x(va_list ap)
{
    char chara = va_arg(ap, int);
    char *hexa = "0123456789abcdef";
    int second = (chara / 16) * 16;
    int secondf = 0;
    for (; second < chara; second++, secondf++);
    my_put_nbr(chara / 16);
    my_putchar(hexa[secondf]);
}