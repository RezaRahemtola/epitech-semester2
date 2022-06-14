##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR        =    src/

SRC            =    main.c \
					map.c \
					game.c \
					move.c \
					end_checks.c \
					error_handling.c

OBJ            =    $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME           =    my_sokoban

CC             =    gcc
CFLAGS         =    -Wall -Wextra
CPPFLAGS       =    -I include -I lib/my/include
LDFLAGS        =    -L lib/my
LDLIBS         =    -lmy -lncurses

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
			make fclean -C tests/ -s

tests_run:
			@make -C tests/ -s
			@./tests/unit_tests

gcovr:	    tests_run
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

debug:		CFLAGS += -g
debug:		re

re:			fclean all

.PHONY: all libs clean fclean tests_run gcovr re
