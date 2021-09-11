##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=		src/main.c \
				src/str_funct.c \
				src/server/server.c \
				src/server/select_command.c \
				src/command/quit.c \
				src/command/log_in.c \
				src/command/noop.c \
				src/command/help.c \
				src/command/pasv.c \
				src/command/cwd.c \
				src/command/del.c \
				src/command/retr.c \
				src/command/store.c \
				src/command/list.c \
				src/client/client.c \
				src/client/client_utils.c \
				src/client/client_handle.c \

OBJ     =       $(SRC:.c=.o)

NAME	=	myftp

NAME_TEST	=	unit_test

CFLAGS  =	-Wall -Wextra -I./include

LDFLAGS =       -lcriterion -lgcov --coverage -I./include

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

test_run : fclean $(OBJ)
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
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME) 5551 `pwd`

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

re:     fclean all