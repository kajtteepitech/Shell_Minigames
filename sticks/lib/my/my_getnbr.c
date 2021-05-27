/*
** PROJECT, 2021
** mygetnbr
** File description:
** zefo
*/

int my_getnbr(char *str)
{
    int pos;
    int signe = 1;
    int nbr;

    pos = 0;
    while (str[pos] != '\0' && (str[pos] == '+' || str[pos] == '-')) {
        if (str[pos] == '-') {
            signe = signe * -1;
        }
        pos = pos + 1;
    }
    str = str + pos;
    nbr = 0;
    pos = 0;
    while (str[pos] >= '0' && str[pos] <= '9') {
        nbr = nbr * 10;
        nbr = nbr - (str[pos] - '0');
        pos = pos + 1;
    }
    return (nbr * signe * -1);
}
