#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct box_s
{
    int x;
    int y;
    struct box_s *next;
}box_t;

typedef struct goal_s
{
    int x;
    int y;
    struct goal_s *next;
}goal_t;

typedef struct list_s
{
    int nb_goal;
    int nb_box;
    int nb_line;
    int p_x, p_y;
    struct box_s *box;
    struct goal_s *goal;
}list_t;

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int str_to_word_array(char *buffer);
void readcmd(char **argv, char **env);
char *readline(void);
int checkstart();
void loop(char **argv, char **env);
int game_loop(char **map, list_t *list);
void bonusfunc(char **av, char **env);
void checkcd(char **env);
int open_file(char *filepath);
int init_map(char **map, list_t *list);
int stop_the_loop(char **map);
int create_list(char **map, int line, int goal);
int game_loop(char **map, list_t *list);
void init_object(list_t *list);
void player_move(int ch, list_t *list);