##
## EPITECH PROJECT, 2021
## libmy
## File description:
## Makefile
##

SRC		=	src/array/my_arrays.c \
			src/my_str_starts.c \
			src/my_strsplit.c \
			src/my_free.c \
			src/my_substr.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

INC		=	include/

AR		=	ar rc
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Wpedantic
CPPFLAGS =	-iquote $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST)

re:     fclean all

.PHONY: all clean fclean install re
