##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile Cpp DAY01
##

SRC		=	main.cpp \
			Character.cpp \
			Warrior.cpp \
			Mage.cpp \
			Priest.cpp \
			Paladin.cpp	\

NAME	=	test

CFLAGS	= -Wall -Wextra

all:	$(NAME)

$(NAME):
		g++ -O3 -o $(NAME) $(SRC) -I .

ex00:
		gcc -O3 -o test00 ex00.c main.c -I.

clean:
		rm -f $(OBJ)

fclean:    clean
		rm -f $(NAME)
		rm -f vgcore.*

re: fclean all

valgrind: fclean
	clear
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME)