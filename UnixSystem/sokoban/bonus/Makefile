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

SRCS           =    $(addprefix $(SRC_DIR), $(SRC))

OBJ            =    $(SRCS:.c=.o)


NAME           =    my_sokoban_bonus

CC             =    gcc
CFLAGS         =    -Wall -Wextra
CPPFLAGS       =    -I include -I ../lib/my/include
LDFLAGS        =    -L ../lib/my
LDLIBS         =    -lmy -lncurses

all:		$(NAME)

$(NAME):	$(OBJ) libs
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

libs:
			make -C ../lib/my

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ../lib/my -s

debug:		CFLAGS += -g
debug:		re

re:			fclean all

.PHONY: all libs clean fclean re
