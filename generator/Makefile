##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

SRC			=	main.c\
				fill_map.c\
				print_maze.c\
				random_direction.c\
				setup_directions.c\
				generate_imperfect_maze.c\
				generate_perfect_maze.c

DIR_SRC =       $(addprefix src/, $(SRC))

OBJ     =       $(DIR_SRC:.c=.o)

LDLIBS		=	-L ../lib/

CPPFLAGS	=	-I include/ -ggdb3

CFLAGS		=	-Wall -Wextra

NAME	= generator

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CPPFLAGS) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
