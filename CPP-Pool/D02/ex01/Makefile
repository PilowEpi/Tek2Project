##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		main.c \
				mem_ptr.c \

OBJ     =       $(SRC:.c=.o)

NAME	=	test

NAME_TEST	=	unit_test

CFLAGS  =	-I. -Wall -Wextra

LDFLAGS =       -lcriterion -lgcov --coverage --I.

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

test_run : fclean $(OBJ)
	CFLAGS += -Wall -Wextra
	gcc -o $(NAME_TEST) $(SRC) $(LDFLAGS)
	./$(NAME_TEST)
	gcovr --exclude tests/
	gcovr -b --exclude tests/

clean:
	rm -f $(OBJ)
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

valgrind: fclean
	clear
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

re:     fclean all