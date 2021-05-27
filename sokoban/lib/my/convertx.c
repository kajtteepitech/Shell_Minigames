/*
** PRINTF PROJECT, 2020
** convert_X
** File description:
** converts a hexadecimal in capital
*/

#include "my.h"
#include <stdarg.h>

void convertx(va_list ap)
{
    char chara = va_arg(ap, int);
    char *hexa = "0123456789ABCDEF";
    int second = (chara / 16) * 16;
    int secondf = 0;
    for (; second < chara; second++, secondf++);
    my_put_nbr(chara / 16);
    my_putchar(hexa[secondf]);
}