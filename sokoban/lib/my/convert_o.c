/*
** PRINTF PROJECT, 2020
** convert_o
** File description:
** converts oct
*/

#include "my.h"
#include <stdarg.h>

void convert_o(va_list ap)
{
    int oct = 0;
    int nb = va_arg(ap, int);

    for (int i = 1; nb != 0; i *= 10) {
        oct = oct + (nb % 8) * i;
        nb /= 8;
    }
    my_put_nbr(oct);
}