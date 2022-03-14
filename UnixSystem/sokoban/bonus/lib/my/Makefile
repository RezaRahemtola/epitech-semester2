##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/strings/concat.c \
	  src/strings/len.c  \
	  src/strings/put.c \
	  src/strings/check_content.c \
	  src/strings/check_type.c \
	  src/strings/compare.c \
	  src/strings/copy.c \
	  src/strings/replace.c \
	  src/strings/memory.c \
	  src/strings/transform.c \
	  src/stringf/my_stringf.c \
	  src/numbers/put.c \
	  src/numbers/check.c \
	  src/numbers/len.c \
	  src/arrays/len.c \
	  src/arrays/memory.c \
	  src/printf/my_printf.c \
	  src/printf/my_printf_flags.c \
	  src/printf/my_printf_l_ll.c \
	  src/maths.c \
	  src/my_sort_int_array.c \
	  src/my_getnbr.c \
	  src/temp.c \
	  src/my_strstr.c \
	  src/my_int_to_base.c \
	  src/my_str_to_word_array.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CFLAGS = -Wall -Wextra
CPPFLAGS = -I include

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			mkdir -p ../../include
			cp include/* ../../include

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
