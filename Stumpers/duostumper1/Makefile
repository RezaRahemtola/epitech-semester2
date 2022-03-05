##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR     =   src/

SRC         =   main.c \
				error_handling.c \
				edge_cases.c \
				fractals.c \
				utils.c

SRCS        =   $(addprefix $(SRC_DIR), $(SRC))

OBJ         =   $(SRCS:.c=.o)

NAME        =   fractals

CC          =   gcc
CFLAGS      =   -Wall -Wextra
CPPFLAGS    =   -I include -I lib/my/include
LDFLAGS     =   -L lib/my
LDLIBS      =   -lmy
LDCSFML     =   -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

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
			make fclean -C tests -s

debug:		CFLAGS += -g
debug:		re
			valgrind --leak-check=full --track-origins=yes \
			./$(NAME) "3" "###@#.#@###" "...@...@..."

tests_run:
			@make -C tests/ -s
			@./tests/unit_tests

gcovr:		tests_run
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

re:			fclean all

.PHONY: all libs clean fclean debug tests_run re
