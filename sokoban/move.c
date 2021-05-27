/*
** PROJECT, 2021
** move
** File description:
** moving the player
*/

#include "my.h"

void init_object(list_t *list)
{
    goal_t *temp_g = list->goal;
    box_t *temp_b = list->box;

    while (list->goal != NULL) {
        mvaddch(list->goal->y, list->goal->x, 'O');
        list->goal = list->goal->next;
    }
    while (list->box != NULL) {
        mvaddch(list->box->y, list->box->x, 'X');
        list->box = list->box->next;
    }
    list->goal = temp_g;
    list->box = temp_b;
    mvaddch(list->p_y, list->p_x, 'P');
    move(list->p_y, list->p_x);
    refresh();
}

int is_move_okay_solo(int p_y, int p_x)
{
    int testch = mvinch(p_y, p_x);

    if ((testch != '#' && testch == ' ') ||
    (testch != '#' && testch == 'O'))
        return (1);
    return (0);
}

int is_move_okay_box(int b_y, int b_x)
{

    int testch = mvinch(b_y, b_x);

    if (testch != '#' && testch != 'X')
        return (1);
    return (0);
}

void player_move(int ch, list_t *list)
{
    ch = getch();

    switch (ch) {
        case KEY_UP:
        move_up(list);
        break;

        case KEY_DOWN:
        move_down(list);
        break;

        case KEY_RIGHT:
        move_right(list);
        break;

        case KEY_LEFT:
        move_left(list);
        break;
    }
}