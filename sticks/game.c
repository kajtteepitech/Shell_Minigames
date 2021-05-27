/*
** PROJECT, 2021
** game
** File description:
** matchstick game functions
*/

#include "my.h"

static bool scan_matches(map_t *map, int *matches, int line)
{
    char *scan;

    my_printf("Matches: ");
    if (!(scan = scan_line()))
        return ((map->status = -1));
    *matches = my_getnbr(scan);
    free(scan);
    if (*matches == 0)
        my_printf("Error: you have to remove at least one match\n");
    else if (*matches < 0)
        my_printf("Error: invalid input (positive number expected)\n");
    else if (*matches > map->matches)
    {
        my_printf("Error: you cannot remove more than ");
        my_put_nbr(map->matches);
        my_printf(" matches per turn\n");
    }
    else if (*matches > take_a_match(map, line - 1))
        my_printf("Error: not enough matches on this line\n");
    else
        return (true);
    return (false);
}

static bool scan_lines(map_t *map, int *line)
{
    char *scan;

    my_printf("Line: ");
    if (!(scan = scan_line()))
        return (map->status = -1);
    *line = my_getnbr(scan);
    free(scan);
    if (*line <= 0 || *line > map->lines)
    {
        my_printf(*line < 0 ?
        "Error: invalid input (positive number expected)\n" :
        "Error: this line is out of range\n");
        return (false);
    }
    return (true);
}

/* note: naive AI, cba this */
static void robot_turn(map_t *map)
{
    int i;
    int n;

    my_printf("\nAI's turn...\n");
    i = -1;
    while (++i < map->lines)
        if ((n = take_a_match(map, i)))
        {
            rm_a_match(map, i + 1, n > 1 ? (rand() % n) + 1 : 1, false);
            break;
        }
    map_display(map);
    if (!destroy_map(map))
        player_turn(map);
    else
    {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        map->status = 1;
    }
}

void player_turn(map_t *map)
{
    int lines;
    int matches;

    my_printf("\nYour turn :\n");
    while (!scan_lines(map, &lines) ||
    (!map->status && !scan_matches(map, &matches, lines)));
    if (map->status == -1 && !(map->status = 0))
        return;
    rm_a_match(map, lines, matches, true);
    map_display(map);
    if (!destroy_map(map))
        robot_turn(map);
    else
    {
        my_printf("You lost, too bad...\n");
        map->status = 2;
    }
}
