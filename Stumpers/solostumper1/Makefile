##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC =   src/main.c \
		src/countwords.c \
		src/pattern_list.c \
		src/lib.c

SRC_TEST = src/countwords.c \
		   src/pattern_list.c \
		   src/lib.c

NAME = countwords

TEST_NAME = unit_tests

FLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):
	@gcc $(FLAGS) -o $(NAME) $(SRC) -I include

clean:
	@find -name "*~" -delete -o -name "#*#" -delete \
	-o -name "vgcore.*" -delete

fclean:	clean
	@rm -f $(NAME)
	@find -name "$(TEST_NAME)*" -delete

re:			fclean all

fclean_tests:	clean
		@find -name "$(TEST_NAME)*" -delete

tests_run:
	@make fclean_tests -s
	@gcc $(FLAGS) -o $(TEST_NAME) $(SRC_TEST) \
	tests/*.c -I include --coverage -lcriterion
	@./$(TEST_NAME)

.PHONY: all clean fclean re fclean_tests tests_run
