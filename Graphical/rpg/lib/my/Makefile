##
## EPITECH PROJECT, 2021
## libmy
## File description:
## Makefile
##

SRC		=	src/array/my_arrays.c \
			src/list/my_list_add.c \
			src/math/my_getnbr.c \
        	src/math/my_nbrlen.c \
            src/math/my_operations.c \
            src/math/my_parsenbr_base.c \
            src/math/my_parsenbr_long.c \
            src/math/my_parsenbr.c \
			src/printf/my_printf.c \
			src/printf/my_printf_bases.c \
			src/printf/my_printf_core.c \
			src/printf/my_printf_formats.c \
			src/printf/my_printf_formatter.c \
			src/printf/my_printf_info.c \
			src/printf/my_printf_numbers.c \
			src/printf/my_printf_parser.c \
			src/printf/my_printf_strings.c \
			src/string/my_str_contains.c \
			src/string/my_str_operations.c \
			src/string/my_str_starts.c \
			src/string/my_strcmp.c \
			src/string/my_strcpy.c \
			src/string/my_strrep.c \
			src/string/my_strsplit.c \
			src/string/my_substr.c \
			src/string/string_search.c \
			src/my_free.c \
			src/my_print.c \
			src/memory_allocation.c \
			src/memory_manipulation.c

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
	$(RM) *.gcda
	$(RM) *.gcno

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
