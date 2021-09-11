##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## rush1
##

SRC        =    src/new.c 		\
				src/array.c 	\
				src/list.c 		\
				src/float.c 	\
				src/int.c 		\
				src/char.c 		\
				src/main.c 		\
				src/product.c 	\
				src/function.c 	\
				src/shopping.c 	\
				src/main_shopping.c \

NAME    =    bonus

FLAGS 	=	-g -std=gnu11 -lm -I./include

CFLAGS	=

all:    $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(FLAGS) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:    clean
		rm -f $(NAME)
		rm -f vgcore.*

re: fclean all


run: fclean all
		./$(NAME)

valgrind: fclean
		clear
		clear
		gcc -g -o $(NAME) $(SRC) $(FLAGS) $(CFLAGS)
		valgrind -s --leak-check=full --track-origins=yes ./$(NAME) | cat -e