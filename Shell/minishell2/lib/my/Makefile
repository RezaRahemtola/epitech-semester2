##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR     =   src/

SRC         =   strings/concat.c \
			    strings/len.c  \
			    strings/put.c \
			    strings/check_content.c \
			    strings/check_type.c \
			    strings/compare.c \
			    strings/copy.c \
			    strings/replace.c \
			    strings/memory.c \
			    strings/transform.c \
			    stringf/my_stringf.c \
			    numbers/put.c \
			    numbers/len.c \
				numbers/maths.c \
			    arrays/len.c \
			    arrays/memory.c \
			    my_getnbr.c \
			    temp.c \
			    my_strstr.c \
			    my_int_to_base.c \
			    my_str_to_word_array.c

OBJ         =    $(addprefix $(SRC_DIR),$(SRC:.c=.o))

NAME        =    libmy.a

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
