##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Tests
##

DIR_GEN        =    ../generator/src/
DIR_SOL        =    ../solver/src/
DIR_TEST       =    src/

SRC_GEN        =
SRC_SOL        =	error_handling.c \
					map.c \
					pos.c
SRC_TEST       =	solver/tests_error_handling.c

SRCS_GEN       =    $(addprefix $(DIR_GEN), $(SRC_GEN))
SRCS_SOL       =    $(addprefix $(DIR_SOL), $(SRC_SOL))
SRCS_TEST      =    $(addprefix $(DIR_TEST), $(SRC_TEST))
ALL            =    $(SRCS_GEN) $(SRCS_SOL) $(SRCS_TEST)

NAME           =    unit_tests

CC             =    gcc
CFLAGS         =    -Wall -Wextra --coverage
CPPFLAGS       =    -iquote ../solver/include -iquote ../generator/include \
					-iquote ../lib/my/include -iquote ../lib/mylist/include
LDFLAGS        =    -L ../lib/my -L ../lib/mylist
LDLIBS         =    -lmy -llist -lcriterion

all:		$(NAME)

$(NAME):	clean
			make -C ../lib/my
			$(CC) -o $(NAME) $(ALL) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
			$(RM) *.gcno
			$(RM) *.gcda

fclean:		clean
			$(RM) $(NAME)

.PHONY: all clean fclean
