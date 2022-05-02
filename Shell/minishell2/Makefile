##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR        =    src/

SRC            =    main.c \
					parsing.c \
					minishell.c \
					input.c \
					init/command.c \
					init/redir.c \
					builtins/builtins.c \
					builtins/cd.c \
					builtins/env.c \
					builtins/setenv.c \
					builtins/unsetenv.c \
					builtins/exit.c \
					execute/exec.c \
					execute/redirections.c \
					parsing/redirections.c \
					parsing/input.c \
					parsing/check_errors.c \

OBJ            =    $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME           =    mysh

CC             =    gcc
CFLAGS         =    -Wall -Wextra
CPPFLAGS       =    -iquote include -iquote lib/my/include \
					-iquote lib/mylist/include
LDFLAGS        =    -L lib/my -L lib/mylist
LDLIBS         =    -lmy -llist

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

tests_run:	re
			python tests/tester.py -ad

debug:		CFLAGS += -g
debug:		re
			mkdir -p logs/
			valgrind --track-origins=yes --leak-check=full \
			./$(NAME) $(ARGS) 2> logs/valgrind.txt

re:			fclean all

.PHONY: all libs clean fclean tests_run debug re
