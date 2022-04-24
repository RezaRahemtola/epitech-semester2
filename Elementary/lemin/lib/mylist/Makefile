##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR     =   src/

SRC 		= 	add.c \
	  			convert.c \
	  			destroy.c \
	 			len.c

OBJ         =    $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME        =    liblist.a

CC          =    gcc
CFLAGS      =    -Wall -Wextra
CPPFLAGS    =    -iquote include

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
