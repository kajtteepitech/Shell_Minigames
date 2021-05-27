/*
** PRINTF PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

struct fmtstruc
{
    char format_char;
    void (*listptr)(va_list);
};

void put_a_str(va_list ap)
{
    char *string;
    string = va_arg(ap, char *);
    my_putstr(string);
}

void put_a_dec(va_list ap)
{
    int dec;
    dec = va_arg(ap, int);
    my_put_nbr(dec);
}

void put_a_char(va_list ap)
{
    int character;
    character = va_arg(ap, int);
    my_putchar(character);
}

static struct fmtstruc fmt[7] = {
    {'s', put_a_str},
    {'d', put_a_dec},
    {'c', put_a_char},
    {'o', convert_o},
    {'b', convert_b},
    {'x', convert_x},
    {'X', convertx}};

int my_printf(char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            for (int j = 0; j < 7; j++) {
                if (format[i] == fmt[j].format_char)
                    fmt[j].listptr(ap);
            }
        }
        else if (format[i] >= 0 && format[i] <= 127)
            write(1, &format[i], 1);
    }
    va_end(ap);
    return (0);
}