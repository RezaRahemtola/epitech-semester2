##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR     =   src/

SRC         =	main.c \
				cesar.c \
				encrypt.c \
				load_buffer.c \
				error_handling.c \
				write_in_crypt.c

OBJ         =   $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME        =   cesar

CC          =   gcc
CFLAGS      =   -Wall -Wextra
CPPFLAGS    =   -I include -I lib/my/include
LDFLAGS     =   -L lib/my
LDLIBS      =   -lmy

all:		$(NAME)

$(NAME):	$(OBJ) libs
			$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS) $(LDLIBS)

libs:
			make -C lib/my

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C lib/my -s

debug:		CFLAGS += -g
debug:		re
			valgrind --leak-check=full --track-origins=yes \
			./$(NAME) $(ARGS) 2> logs/valgrind.txt

tests_run: 	all
			./tests/functionnal_tests

re:			fclean all

.PHONY: all libs clean fclean debug tests_run re
