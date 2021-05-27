/*
** PROJECT, 2020
** revstr
** File description:
** revstr for stumper
*/

int len(char *str)
{
    unsigned int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int ir = len(str) - 1;
    char tmp;

    if (i >= 0) {
        while (i < ir) {
            tmp = str[i];
            str[i] = str[ir];
            str[ir] = tmp;
            ++i;
            --ir;
        }
    }
    return (str);
}
