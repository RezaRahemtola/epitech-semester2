##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/

MAIN_DIR	=	$(SRC_DIR)main/

MENUS_DIR	=	$(SRC_DIR)menus/

CONFIG_DIR	= 	$(SRC_DIR)configuration/

DATA_DIR	=	$(SRC_DIR)data/

INVENTORY_DIR = $(SRC_DIR)inventory/

PARTICLES_DIR = $(SRC_DIR)particles/

MAIN_SRC	=	main.c \
				events.c \
				init.c \
				game.c \
				scaling.c \
				stats.c \
				destroy.c \
				types.c \
				entities.c \
				xp.c \
				npcs.c \
				window.c \
				player.c

MENUS_SRC	=	hud/destroy.c \
				hud/init.c \
				hud/init_stats.c \
				hud/health.c \
				hud/listener.c \
                hud/show.c \
                hud/stats.c \
                hud/xp.c \
                main/destroy.c \
               	main/events.c \
             	main/init.c \
                main/resize.c \
                main/window.c \
                map/collisions.c \
                map/config.c \
                map/entities.c \
                map/events.c \
                map/init.c \
                map/movement.c \
                map/npcs.c \
                map/perspective.c \
                map/positions.c \
                map/window.c \
                map/zoom.c \
				pause/pause.c \
				settings/settings.c \
				settings/utils.c \
				how_to_play/how_to_play.c

INVENTORY_SRC = inventory.c \
				drag_and_drop.c \
				init.c

CONFIG_SRC	=	parser.c \
				configuration_getters.c \
				configuration_setters.c

DATA_SRC	=	data.c

PARTICLES_SRC = particle.c \
				motion/particle_motion.c \
				motion/particle_motion_offsets.c \
				motion/particle_position_motion.c \
				motion/particle_rotation_motion.c \
				motion/particle_scale_motion.c \
				motion/particle_opacity_motion.c \
				rain.c \
				updater.c \
				renderer.c

OBJ			=	$(addprefix $(MAIN_DIR),$(MAIN_SRC:.c=.o)) \
				$(addprefix $(MENUS_DIR),$(MENUS_SRC:.c=.o)) \
				$(addprefix $(INVENTORY_DIR),$(INVENTORY_SRC:.c=.o)) \
				$(addprefix $(CONFIG_DIR),$(CONFIG_SRC:.c=.o)) \
				$(addprefix $(DATA_DIR),$(DATA_SRC:.c=.o)) \
				$(addprefix $(PARTICLES_DIR),$(PARTICLES_SRC:.c=.o))


NAME		=	my_rpg

HEADERS    		=	include/
MY_HEADERS 		=	lib/my/include/
CSFML_HEADERS	=	lib/mycsfml/include/

CC			=	gcc
CFLAGS		=	-Wall -Wextra
CPPFLAGS	=	-iquote $(HEADERS) -iquote $(MY_HEADERS) \
				-iquote $(CSFML_HEADERS)
LDFLAGS		=	-L lib/my/ -L lib/mycsfml
LDLIBS		=	-lmy -lmycsfml
LDCSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:		$(NAME)

$(NAME):	$(OBJ) libs
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LDCSFML)

libs:
			make -C lib/my/
			make -C lib/mycsfml

clean:
			$(RM) $(OBJ)
			make -C lib/my clean
			make -C lib/mycsfml clean

fclean:		clean
			make fclean -C lib/my
			make fclean -C lib/mycsfml
			$(RM) $(NAME)

debug:		CFLAGS += -g
debug:		re
			valgrind --leak-check=full --track-origins=yes \
			./$(NAME) $(ARGS) 2> logs/valgrind.txt

re:			fclean all

.PHONY: all libs clean fclean debug re
