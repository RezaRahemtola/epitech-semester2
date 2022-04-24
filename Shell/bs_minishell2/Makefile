##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC            =    main.c

OBJ            =    $(SRC:.c=.o)

NAME           =    my_exec2

CC             =    gcc
CFLAGS         =    -Wall -Wextra
CPPFLAGS       =	-iquote lib/my/include
LDFLAGS        =	-L lib/my
LDLIBS         =	-lmy

all:		$(NAME)

$(NAME):	$(OBJ) libs
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

libs:
			make -C lib/my

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all libs clean fclean re
