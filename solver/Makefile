##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Make Dante
##

SRC = src/resolve.c \
		src/map_handeling.c \
		src/create_heads.c \
		src/createnewnode.c \
		src/look.c \
		src/my_str_to_word_array.c \
		src/my_strndup.c \
		src/past_handeling.c \
		src/display.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I include/ -Wall -Wextra -g3

NAME = solver

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lm

debug:
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lm

clean:
	rm -rf $(OBJ)
	rm -rf *~

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: clean fclean re debug
