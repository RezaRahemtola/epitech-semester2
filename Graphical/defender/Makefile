##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/

SRC			=	main.c \
				defender.c \
				enemies.c \
				display.c \
				error_handling.c \
				finder.c \
				map.c \
				events.c \
				start_menu.c \
				sprites.c \
				towers.c \
				types.c \
				game/pause.c \
				game/play.c \
				game/game.c \
				game/building_menu.c \
				game/buildings.c \
				game/shots.c \
				game/damage.c \
				game/waves.c \
				game/healthbar.c

OBJ			=	$(addprefix $(SRC_DIR),$(SRC:.c=.o))

INCLIB		=	-I lib/my/include -I lib/mycsfml/include -I lib/mylist/include

NAME		=	my_defender

CC			=	gcc
CFLAGS		=	-Wall -Wextra
CPPFLAGS	=	-I include $(INCLIB)
LDFLAGS		=	-L lib/my -L lib/mycsfml
LDLIBS		=	-lmy -lmycsfml -lm
LDCSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:		$(NAME)

$(NAME):	$(OBJ) libs
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LDCSFML)

libs:
			make -C lib/my
			make -C lib/mycsfml

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C lib/my -s
			make fclean -C lib/mycsfml -s

debug:		CFLAGS += -g
debug:		re
			valgrind --leak-check=full --track-origins=yes ./$(NAME) \
			tests/samples/basic_map 2> logs/valgrind.txt

re:			fclean all

.PHONY: all libs clean fclean re
