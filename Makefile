##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

NAME	= dante_project

all:  $(NAME)
	make -C generator/
	make -C solver/

clean:
		make clean -C generator/
		make clean -C solver/

fclean: clean
		make fclean -C generator/
		make fclean -C solver/
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean make_libs dante_project make
