##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Tests
##

SRC_DIR        =    ../src/
SRC_TEST_DIR   =    src/

SRC            =    error_handling.c \
					end_checks.c \
					map.c
SRC_TEST       =    tests_error_handling.c \
					tests_end_checks.c \
					tests_map.c

SRCS           =    $(addprefix $(SRC_DIR), $(SRC))
SRCS_TEST      =    $(addprefix $(SRC_TEST_DIR), $(SRC_TEST))
ALL            =    $(SRCS) $(SRCS_TEST)

NAME           =    unit_tests

CC             =    gcc
CFLAGS         =    -Wall -Wextra --coverage
CPPFLAGS       =    -I ../include
LDFLAGS        =    -L ../lib/my
LDLIBS         =    -lmy -lcriterion

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
