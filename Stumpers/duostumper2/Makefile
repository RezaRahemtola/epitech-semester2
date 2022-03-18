##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR     =   src/

SRC         =   main.c \
				error_handling.c \
				params.c \
				replace.c \
				map.c \
				game.c \
				input.c \
				win_checks.c \
				utils.c

OBJ         =   $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME        =   connect4

CC          =   gcc
CFLAGS      =   -Wall -Wextra
CPPFLAGS    =   -I include -I lib/my/include
LDFLAGS     =   -L lib/my
LDLIBS      =   -lmy

all:		$(NAME)

$(NAME):	$(OBJ) libs
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

libs:
			make -C lib/my

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C lib/my -s

debug:		CFLAGS += -g
debug:		re
			valgrind --leak-check=full --track-origins=yes \
			./$(NAME)

re:			fclean all

.PHONY: all libs clean fclean debug re
