/*
** PROJECT, 2021
** chained lists
** File description:
** chained lists for sokoban
*/

#include "my.h"

list_t *push_back_box(list_t *li, int y, int x)
{
    box_t *element = malloc(sizeof(*element));

    if (element == NULL)
        my_printf("Malloc error from chained list box\n");

    element->x = x;
    element->y = y;
    element->next = NULL;

    if (li->box == NULL) {
        li->box = element;
        return (li);
    }

    box_t *temp;
    temp = li->box;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return (li);
}

list_t *push_back_goal(list_t *li, int y, int x)
{
    goal_t *element = malloc(sizeof(*element));

    if (element == NULL)
        my_printf("Malloc error from chained list goal\n");

    element->x = x;
    element->y = y;
    element->next = NULL;

    if (li->goal == NULL) {
        li->goal = element;
        return (li);
    }

    goal_t *temp;
    temp = li->goal;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return (li);
}

int create_list(char **map, int line, int goal)
{
    int i = 0;
    int j = 0;
    list_t *list = malloc(sizeof(*list));
    list->box = NULL;
    list->goal = NULL;
    list->nb_line = line, list->nb_box = goal, list->nb_goal = goal;

    for (; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\n' && map[i][j] != '\0'; j++) {
            if (map[i][j] == 'X')
                list = push_back_box(list, i, j);
            if (map[i][j] == 'O')
                list = push_back_goal(list, i, j);
            if (map[i][j] == 'P') {
                list->p_y = i;
                list->p_x = j;
            }
        }
    }
    return (init_map(map, list));
}