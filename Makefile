##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make a file
##

SRC 	=	lib/my/my_putchar.c 	\
			lib/my/my_putstr.c 		\
			lib/my/BSQ.c			\
			lib/my/my_strlen.c 		\
			lib/my/my_strncpy.c		\
			lib/my/my_modified_strlen.c \
			lib/my/find_the_size_of_the_square.c \

OBJ 	= 	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

test_run:
		gcc -o unit_test bonus/testcriterion.c $(SRC) -lcriterion
		./unit_test

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
