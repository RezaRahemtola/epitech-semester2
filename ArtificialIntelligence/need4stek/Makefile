##
## EPITECH PROJECT, 2021
## need4steck
## File description:
## Makefile
##

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME		=	ai

TEST		=	unit_tests

## ==========================[PATHS]==========================

SRC_DIR		=	src/

INIT_DIR	=	init/

LIDAR_DIR	=	lidar/

## ===========================[SRC]===========================

SRC_INIT	=	$(INIT_DIR)init_car.c	\

SRC_LIDAR	=	$(LIDAR_DIR)get_info_lidar.c	\
				$(LIDAR_DIR)end.c				\

SRC_MAIN	=	ai.c				\
				main.c				\
				send_instructions.c	\
				compute.c			\

SRC			=	$(addprefix $(SRC_DIR), $(SRC_MAIN))	\
				$(addprefix $(SRC_DIR), $(SRC_INIT))	\
				$(addprefix $(SRC_DIR), $(SRC_LIDAR))	\

OBJ			=	$(SRC:.c=.o)

## =========================[OPTIONS]=========================

INC			=	include/
LIBINC		=	lib/my/include/

TESTS		=	tests/test_ai.c

CC			=	gcc
RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Wpedantic
CPPFLAGS	=	-iquote $(INC) -iquote $(LIBINC)
TESTFLAGS	=	--coverage -lcriterion
LDLIBS		=	-lmy
LDFLAGS		=	-L lib/my/

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_M)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	make clean -C lib/my/

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST)
	make fclean -C lib/my/

re:	fclean all

tests_run: $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	make -C lib/my/
	$(CC) -o $(TEST) $(OBJ) $(TESTS) $(TESTFLAGS)
	./$(TEST)

## ===========================[END]===========================

.PHONY: all re clean fclean tests_run
