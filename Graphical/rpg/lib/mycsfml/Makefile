##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## MY CSFML
##

SRC_DIR     =   src/

SRC         = 	audio.c \
				buttons.c \
	  			clock.c \
	  			color.c \
	  			draw.c \
	  			elements.c \
	  			events.c \
	  			framebuffer.c \
	  			game_object/create_destroy.c \
	  			game_object/display.c \
	  			game_object/move.c \
	  			game_object/utils.c \
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
