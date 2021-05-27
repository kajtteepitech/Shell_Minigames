##
## PROJECT, 2020
## libmy.a
## File description:
## Makefile
##

SCR = $(wildcard lib/my/*.c)

OBJ = $(SCR:.c=.o)

LIB = lib/my/libmy.a

SRC = $(wildcard *.c)

FLAGS = -I./include -L./lib/my -lmy -lncurses

NAME = sticks

all:	$(LIB)
	$(CC) $(OBJ) -o $(NAME) $(SRC) $(FLAGS)

$(LIB): $(OBJ)
	$(AR) rsc $(LIB) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) '#*#'

fclean: clean
	$(RM) -f $(NAME)
	$(RM) $(LIB)

re:	fclean all
