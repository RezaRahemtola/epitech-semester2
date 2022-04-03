##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR        =    src/

SRC            =    main.c \
					get_tetriminos.c \
					tetriminos.c \
					debug.c \
					clock.c \
					rotate_piece.c \
					params.c \
					game/game.c \
					game/move.c \
					game/map.c \
					game/tetri.c \
          			game/handle_input.c \
					game/next.c \
					game/scores.c \
					game/preview.c \
					scores/get_score.c \
					scores/stock_score.c \
					scores/print_result.c \

OBJ            =    $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME           =    tetris

CC             =    gcc
CFLAGS         =    -Wall -Wextra
CPPFLAGS       =    -iquote include -iquote lib/my/include \
					-iquote lib/mylist/include
LDFLAGS        =    -L lib/my -L lib/mylist
LDLIBS         =    -lmy -lncurses -llist

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
			make fclean -C tests/ -s

tests_run:
			@make -C tests/ -s
			@./tests/unit_tests

gcovr:	    tests_run
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

debug:		CFLAGS += -g
debug:		re
			valgrind --leak-check=full --track-origins=yes \
			./$(NAME) $(ARGS) 2> logs/valgrind.txt | cat -e

re:			fclean all

.PHONY: all libs clean fclean tests_run gcovr re
