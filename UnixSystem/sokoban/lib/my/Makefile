##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/strings/len.c  \
	  src/strings/put.c \
	  src/strings/check_content.c \
	  src/strings/compare.c \
	  src/strings/copy.c \
	  src/strings/memory.c \
	  src/arrays/len.c \
	  src/arrays/memory.c \
	  src/maths.c \
	  src/my_str_to_word_array.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CFLAGS = -Wall -Wextra
CPPFLAGS = -I include

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
