##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR     =   include/

SRC         =	main.c \
		parsing.c \
		display.c \
		fight.c

OBJ         =   $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME        =   pokemon

CC          =   gcc
CFLAGS      =   -Wall -Wextra
CPPFLAGS    =   -I src -I lib/my/src -I lib/mylist/include
LDFLAGS     =   -L lib/my -L lib/mylist
LDLIBS      =   -lmy -llist

all:		$(NAME)

$(NAME):	$(OBJ) libs
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

libs:
		make -C lib/my
		make -C lib/mylist

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		make fclean -C lib/my -s
		make fclean -C lib/mylist -s

debug:		CFLAGS += -g
debug:		re
		mkdir -p logs
		valgrind --leak-check=full --track-origins=yes \
		./$(NAME) $(ARGS) 2> logs/valgrind.txt

re:		fclean all

.PHONY: all libs clean fclean debug re
