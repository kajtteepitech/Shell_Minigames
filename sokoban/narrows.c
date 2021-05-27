/*
** PROJECT, 2021
** narrows
** File description:
** to move player
*/

#include "my.h"

void move_up(list_t *list)
{
    box_t *temp = list->box;

    while (list->box != NULL) {
        if ((list->p_y-1 == list->box->y)
        && (list->p_x == list->box->x)) {
            if (is_move_okay_box(list->box->y-1, list->box->x)) {
                list->p_y -= 1;
                list->box->y -= 1;
                list->box = temp;
                return;
            }
        }
        list->box = list->box->next;
    }
    list->box = temp;
    if (is_move_okay_solo(list->p_y-1, list->p_x)) {
        list->p_y -= 1;
    }
}

void move_down(list_t *list)
{
    box_t *temp = list->box;

    while (list->box != NULL) {
        if ((list->p_y+1 == list->box->y)
        && (list->p_x == list->box->x)) {
            if (is_move_okay_box(list->box->y+1, list->box->x)) {
                list->p_y += 1;
                list->box->y += 1;
                list->box = temp;
                return;
            }
        }
        list->box = list->box->next;
    }
    list->box = temp;
    if (is_move_okay_solo(list->p_y+1, list->p_x)) {
        list->p_y += 1;
    }
}

void move_left(list_t *list)
{
    box_t *temp = list->box;

    while (list->box != NULL) {
        if ((list->p_y == list->box->y)
        && (list->p_x-1 == list->box->x)) {
            if (is_move_okay_box(list->box->y, list->box->x-1)) {
                list->p_x -= 1;
                list->box->x -= 1;
                list->box = temp;
                return;
            }
        }
        list->box = list->box->next;
    }
    list->box = temp;
    if (is_move_okay_solo(list->p_y, list->p_x-1)) {
        list->p_x -= 1;
    }
}

void move_right(list_t *list)
{
    box_t *temp = list->box;

    while (list->box != NULL) {
        if ((list->p_y == list->box->y)
        && (list->p_x+1 == list->box->x)) {
            if (is_move_okay_box(list->box->y, list->box->x+1)) {
                list->p_x += 1;
                list->box->x += 1;
                list->box = temp;
                return;
            }
        }
        list->box = list->box->next;
    }
    list->box = temp;
    if (is_move_okay_solo(list->p_y, list->p_x+1)) {
        list->p_x += 1;
    }
}