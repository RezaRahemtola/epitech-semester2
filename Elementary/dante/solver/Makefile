##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR        =    src/

SRC            =    main.c \
					error_handling.c \
					map.c \
					solver.c \
					pos.c

OBJ            =    $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME           =    solver

CC             =    gcc
CFLAGS         =    -Wall -Wextra
CPPFLAGS       =    -iquote include -iquote ../lib/my/include \
					-iquote ../lib/mylist/include
LDFLAGS        =    -L ../lib/my -L ../lib/mylist
LDLIBS         =    -lmy -llist

all:		$(NAME)

$(NAME):	$(OBJ) libs
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

libs:
			make -C ../lib/my
			make -C ../lib/mylist -s

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ../lib/my -s
			make fclean -C ../lib/mylist -s

debug:		CFLAGS += -g
debug:		re

re:			fclean all

.PHONY: all libs clean fclean re
