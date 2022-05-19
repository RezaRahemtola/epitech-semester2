##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR     =   src/

SRC         = 	strings/len.c  \
			    strings/put.c \
			    strings/check_content.c \
			    strings/copy.c \
			    strings/memory.c \
				strings/split.c \
			    arrays/len.c \
			    arrays/memory.c

OBJ         =    $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME        =    libmy.a

CC          =    gcc
CFLAGS      =    -Wall -Wextra
CPPFLAGS    =    -I include

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
