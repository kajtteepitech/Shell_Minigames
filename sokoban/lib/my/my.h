/*
** PROJECT, 2020
** include.h
** File description:
** test
*/

#include <stdarg.h>

void my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
int my_printf(char *format, ...);
void convert_o(va_list ap);
void convert_b(va_list ap);
void convert_x(va_list ap);
void convertx(va_list ap);