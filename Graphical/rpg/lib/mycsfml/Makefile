##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## MY CSFML
##

SRC_DIR     =   src/

SRC         = 	audio.c \
				buttons.c \
	  			elements.c \
	  			events.c \
	  			text.c \
	  			window.c

OBJ         =    $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME        =    libmycsfml.a

CC          =    gcc
CFLAGS      =    -Wall -Wextra
CPPFLAGS    =    -iquote include

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
