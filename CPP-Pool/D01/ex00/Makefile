##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile Cpp DAY01
##

SRC		=	z.c

NAME	=	z

all:	$(NAME)

$(NAME):
		gcc -O3 -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:    clean
		rm -f $(NAME)
		rm -f vgcore.*

re: fclean all

valgrind: fclean
	gcc -g -O3 -o $(NAME) $(SRC)
	valgrind -s --leak-check=full --track-origins=yes ./$(NAME)