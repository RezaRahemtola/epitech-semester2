##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Tests
##

SRC_DIR        =    ../src/
SRC_TEST_DIR   =    src/

SRC            =	params.c \
					tetriminos.c \
					get_tetriminos.c
SRC_TEST       =	tests_params.c \
					tests_load_tetri_errors.c

SRCS           =    $(addprefix $(SRC_DIR), $(SRC))
SRCS_TEST      =    $(addprefix $(SRC_TEST_DIR), $(SRC_TEST))
ALL            =    $(SRCS) $(SRCS_TEST)

NAME           =    unit_tests

CC             =    gcc
CFLAGS         =    -Wall -Wextra --coverage
CPPFLAGS       =    -iquote ../include -iquote ../lib/my/include \
					-iquote ../lib/mylist/include
LDFLAGS        =    -L ../lib/my -L ../lib/mylist
LDLIBS         =    -lmy -lcriterion -llist

all:		$(NAME)

$(NAME):	clean libs
			$(CC) -o $(NAME) $(ALL) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

libs:
			make -C ../lib/my
			make -C ../lib/mylist

clean:
			$(RM) *.gcno
			$(RM) *.gcda

fclean:		clean
			$(RM) $(NAME)


.PHONY: all clean fclean
