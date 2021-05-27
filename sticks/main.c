/*
** PROJECT, 2021
** main
** File description:
** main for bs matchstick
*/

#include "my.h"

static char *app(char *str, char c)
{
    char *ap;
    int i;
    int j;

    i = (j = 0);
    while (str && str[i] && ++i);
    if (!(ap = malloc(sizeof(char) * (i + 2))))
        return (NULL);
    while (str && j < i) {
        ap[j] = str[j];
        j++;
    }
    ap[j] = c;
    ap[j + 1] = 0;
    if (str)
        free(str);
    return (ap);
}

char *scan_line()
{
    char *str;
    char buffer[1];
    int error;

    str = NULL;
    while ((error = read(0, buffer, 1))) {
        if (error == -1) {
            if (str)
                free(str);
            return (NULL);
        }
        if (buffer[0] == '\n')
            return (str);
        else if (buffer[0] == EOF || !(str = app(str, buffer[0])))
            break;
    }
    if (str)
        free(str);
    return (NULL);
}

static map_t *init_map(int lines, int matches)
{
    map_t *map;
    if (!(map = malloc(sizeof(map_t))))
        return (NULL);
    map->sticks = 1 + (lines - 1) * 2;
    if (!(map->take = map_create(lines, map->sticks)))
        return (NULL);
    map->lines = lines;
    map->matches = matches;
    map->status = 0;
    return (map);
}

static void free_all(map_t *map)
{
    int i = -1;

    while (++i < map->lines)
        free(map->take[i]);
    free(map->take);
    free(map);
}

int main(int argc, char **argv)
{
    int lines;
    int matches;
    int status;

    map_t *map;
    if (argc != 3 ||
    !(lines = my_getnbr(argv[1])) || lines < 0 || lines > 100 ||
    !(matches = my_getnbr(argv[2])) || matches < 0 ||
    !(map = init_map(lines, matches)))
        return (84);
    map_display(map);
    player_turn(map);
    status = map->status;
    free_all(map);
    return (status);
}