/*
** PROJECT, 2021
** map
** File description:
** map gesture for matchstick
*/

#include "my.h"

char **map_create(int line, int stick)
{
    char **map;
    int a = -1;
    int b = -1;
    int c;

    if (!(map = malloc(sizeof(char *) * line)))
        return (NULL);
    while (++a < line) {
        map[a] = malloc(sizeof(char) * stick);
        c = a * 2 + 1;
        while (++b < stick) {
            map[a][b] = 0;
        }
        b = (stick - c) / 2;
        while (c--) {
            map[a][b++] = '|';
        }
    }
    return (map);
}

void map_display(map_t *map)
{
    int a = -1;
    int b;
    char c;

    while (++a < map->lines + 2) {
        b = -1;
        while (++b < map->sticks + 2) {
            if (!b || b == map->sticks + 1 || a == 0 || a == map->lines + 1) {
                my_putchar ('*');
            }
            else
                my_putchar((c = map->take[a - 1][b - 1]) ? c : ' ');
        }
        my_putchar('\n');
    }
}

int take_a_match(map_t *map, int line)
{
    int i = -1;
    int m = 0;

    while (++i < map->sticks) {
        m += map->take[line][i] == '|' ? 1 : 0;
    }
    return (m);
}

void rm_a_match(map_t *map, int line, int matches, bool player)
{
    int i = map->sticks;
    char *c;

    my_printf(player ? "Player" : "AI");
    my_printf(" removed ");
    my_put_nbr(matches);
    my_printf(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    while (--i >= 0 && matches) {
        if (*(c = &map->take[line - 1][i]) == '|' && matches--)
            *c = 0;
    }
}

bool destroy_map(map_t *map)
{
    int i = -1;
    int a;

    while (++i < map->lines && (a = -1)) {
        while (++a < map->sticks) {
            if (map->take[i][a] == '|')
                return (false);
        }
    }
    return (true);
}