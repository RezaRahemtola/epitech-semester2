##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR        =    src/

SRC            =    main.c \
					error_handler.c \
					generator.c		\
					backtracker.c	\
					maze_utils.c \
					imperfect.c \
					finisher.c

OBJ            =    $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME           =    generator

CC             =    gcc
CFLAGS         =    -Wall -Wextra
CPPFLAGS       =    -iquote include -iquote ../lib/my/include
LDFLAGS        =    -L ../lib/my
LDLIBS         =    -lmy

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
