/*
** PROJECT, 2021
** str to wrd array
** File description:
** str to word array for sokoban
*/

#include "../../include/my.h"

int count_line(char *buffer)
{
    int i = 0, line = 0;

    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            line++;
    }
    line++;
    return (line);
}

void count_char(char *buffer, int *index)
{
    for (; buffer[*index] != '\n' && buffer[*index] != '\0'; *index += 1);
    *index += 1;
}

void count_object(int *goal, int *box, int *player, char c)
{
    if (c == 'P')
        *player += 1;
    else if (c == 'X')
        *box += 1;
    else if (c == 'O')
        *goal += 1;
}

int check_object(int player, int box, int goal)
{
    if (player == 0 || box == 0 || goal == 0)
        return (1);
    else if (box < goal || goal < box)
        return (1);
    return (0);
}

int str_to_word_array(char *buffer)
{
    int line = count_line(buffer), i = 0, j = 0;
    int index = 0, tmp = 0, tmp_2 = 0, goal = 0, box = 0, player = 0;
    char **map = malloc(sizeof(char *) * (line+1));

    for (i = 0; i != line; i++) {
        tmp = index;
        tmp_2 = index;
        count_char(buffer, &index);
        tmp = index-tmp;
        map[i] = malloc(sizeof(char) * (tmp+1));
        for (j = 0; j != tmp; j++, ++tmp_2) {
            count_object(&goal, &box, &player, buffer[tmp_2]);
            map[i][j] = buffer[tmp_2];
        }
        map[i][j] = '\0';
    }
    map[i] = NULL;
    free(buffer);
    if (check_object(player, box, goal) == 1)
        stop_the_loop(map);
    return (create_list(map, line, goal));
}