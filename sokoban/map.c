/*
** PROJECT, 2021
** map
** File description:
** display and free a map
*/

#include "my.h"

int init_map(char **map, list_t *list)
{
    int max_y = 0;
    int max_x = 1;

    initscr();
    noecho();
    getmaxyx(stdscr, max_y, max_x);
    keypad(stdscr, TRUE);
    if (max_y < list->nb_line || max_x < 1) {
        endwin();
        return (my_printf("Terminal not wide enough\n"));
    }
    curs_set(0);
    return (game_loop(map, list));
}

int open_file(char *filepath)
{
    int fs = 0;
    int size = 0;
    struct stat buff;

    fs = open(filepath, O_RDONLY);
    if (fs == -1) {
        my_printf("Can't open the file\n");
        return (84);
    }
    stat(filepath, &buff);
    size = buff.st_size;
    char *buffer = malloc(sizeof(char) * (size+1));
    if (buffer == NULL)
        return (my_printf("Buffer NULL\n"));
    read(fs, buffer, size);
    buffer[size] = '\0';
    close(fs);
    return (str_to_word_array(buffer));
}

void display_map(char **map)
{
    int i = 0, j = 0;

    for (; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\0' || map[i][j] != '\0'; j++) {
            if (map[i][j] == '#')
                mvaddch(i, j, '#');
            else
                mvaddch(i, j, ' ');
        }
    }
}

void free_map(char **map)
{
    int i = 0;

    for (; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}