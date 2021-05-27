/*
** PRINTF PROJECT, 2020
** convert_b
** File description:
** conversion binary
*/

#include "my.h"
#include <stdarg.h>

void convert_b(va_list ap)
{
    int bin = 0;
    int one = 1;
    int remainder;
    int nb = va_arg(ap, int);

    while (nb != 0) {
        remainder = nb % 2;
        nb = nb / 2;
        bin = bin + remainder * one;
        one = one * 10;
    }
    my_put_nbr(bin);
}