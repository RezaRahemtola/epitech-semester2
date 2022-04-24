##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME           =    lem_in

## ==========================[PATHS]==========================

SRC_DIR			=	src/

MAIN_PATH		= 	$(SRC_DIR)main/

PARS_PATH		= 	$(SRC_DIR)parsing/

## ===========================[SRC]===========================

SRC_MAIN		=	$(MAIN_PATH)main.c						\
					$(MAIN_PATH)lemin.c						\
					$(MAIN_PATH)rooms.c						\

SRC_PARS		=	$(PARS_PATH)init.c						\
					$(PARS_PATH)parsing.c					\
					$(PARS_PATH)utils.c						\
					$(PARS_PATH)rooms.c						\
					$(PARS_PATH)tunnels.c					\
					$(PARS_PATH)clean_lines.c				\

SRC				=	$(SRC_MAIN)								\
					$(SRC_UTIL)								\
					$(SRC_PARS)								\

OBJ            =    $(SRC:.c=.o)

## =========================[OPTIONS]=========================

CC             =    gcc

CFLAGS         =    -Wall -Wextra

CPPFLAGS       =    -iquote include -iquote lib/my/include \
					-iquote lib/mylist/include

LDFLAGS        =    -L lib/my -L lib/mylist

LDLIBS         =    -lmy -llist

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

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
			./$(NAME) < $(ARGS) 2> logs/valgrind.txt | cat -e

re:			fclean all

## ===========================[END]===========================

.PHONY: all libs clean fclean tests_run gcovr debug re
