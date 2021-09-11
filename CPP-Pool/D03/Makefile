##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC	=	init_string.c \
		assign_string.c \
		append_string.c \
		info_string.c	\
		compare_copy_string.c	\
		find_string.c	\
		insert_string.c	\
		utils_string.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring.a

NAME_TEST	=	unit_test

CMP	=	gcc

CFLAGS	= -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

tests_run:
	$(CMP) -o $(NAME_TEST) $(SRC_TEST) $(SRC) -lcriterion --coverage -I ../include
	find . -type f -name "test*.gcno" -delete
	find . -type f -name "test*.gcda" -delete
	./$(NAME_TEST)

clean:
	rm -f $(OBJ)
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete
	find . -type f -name "unit_test" -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all