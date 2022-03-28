##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

all:		libs
			make -C generator/
			make -C solver/

libs:
			make -C lib/my

clean:
			make clean -C generator/
			make clean -C solver/

fclean:
			make fclean -C lib/my -s
			make fclean -C lib/mylist -s
			make fclean -C tests/ -s
			make fclean -C generator/ -s
			make fclean -C solver/ -s

tests_run:
			@make -C tests/ -s
			@./tests/unit_tests

gcovr:	    tests_run
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

re:			fclean all

.PHONY: all libs clean fclean tests_run gcovr re
