##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=		main.cpp \
				AEnemy.cpp \
				AWeapon.cpp \
				Character.cpp \
				PlasmaRifle.cpp \
				RadScorpion.cpp \
				SuperMutant.cpp \
				PowerFist.cpp \

NAME	=	test

CMP		=	g++

NAME_TEST	=	unit_test

CFLAGS  =	-Wall -Wextra

all:    $(NAME)

$(NAME):
	$(CMP) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

valgrind: fclean
	clear
	$(CMP) -o $(NAME) $(SRC) $(CFLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

re:     fclean all