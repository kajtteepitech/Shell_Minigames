/*
** PROJECT, 2021
** header
** File description:
** main of sokoabn
*/

#include "my.h"

int stop_the_loop(char **map)
{
    free_map(map);
    my_printf("Invalid P/X/O\n\
Make sure box == goal and only one P\n");
    return (84);
}

void check_win(list_t *list, int *i)
{
    int result = 0;
    goal_t *temp_g = list->goal;
    box_t *temp_b = list->box;

    while (list->goal != NULL) {
        while (list->box != NULL) {
            if ((list->goal->x == list->box->x)
            && (list->goal->y == list->box->y)) {
                result += 1;
            }
            list->box = list->box->next;
        }
        list->box = temp_b;
        list->goal = list->goal->next;
    }
    list->goal = temp_g;
    list->box = temp_b;
    if (result == list->nb_goal)
        *i = result;
}

int game_loop(char **map, list_t *list)
{
    int i = 0;
    int ch = 0;

    while (i != list->nb_goal) {
        clear();
        display_map(map);
        init_object(list);
        player_move(ch, list);
        check_win(list, &i);
        refresh();
    }
    display_map(map);
    refresh();
    endwin();
    free_map(map);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_printf("Too much/invalid arguments\n");
        return (84);
    }
    else {
        return (open_file(argv[1]));
    }
    return (0);
}