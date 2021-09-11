##
## EPITECH PROJECT, 2019
## project
## File description:
## Makefile
##

SRC	=	src/cmds/cli_creat.c\
		src/cmds/login.c	\
		src/cmds/sub.c		\
		src/cmds/user.c		\
		src/log/create_log.c\
		src/log/error.c		\
		src/log/ev.c		\
		src/log/ev_cat.c	\
		src/log/print.c		\
		src/log/private.c	\
		src/log/single.c	\
		src/log/sub_log.c	\
		src/logger.c		\
		src/loop.c			\
		src/p_utils.c		\
		src/parse.c			\

SRC_MAIN =		src/main.c			\

SRC_TEST =		../tests/redirect_all_std.c				\
				../tests/client/use_cmd.c 				\
				../tests/client/create_cmd.c 			\
				../tests/client/list_cmd.c 				\
				../tests/client/help_cmd.c 				\
				../tests/client/login_cmd.c 			\
				../tests/client/sub_cmd.c 			\
				../tests/client/user_cmd.c 			\
				../tests/client/split_quoted.c 		\
				../tests/client/parse_one.c 		\
				../tests/client/create_log_t.c 		\
				../tests/client/error_log.c 		\
				../tests/client/ev_log.c 		\
				../tests/client/ev_cat_log.c 		\
				../tests/client/print_log.c 		\
				../tests/client/private_log.c 		\
				../tests/client/single_log.c 		\
				../tests/client/sub_log_t.c 		\
				../tests/client/logger_test.c 		\

NAME_TEST	=	unit_test_cli

OBJ	=	$(SRC:.c=.o)

NAME	=	myteams_cli

CFLAGS	=	-Iinclude -I../libs/myteams -L../libs/myteams -lmyteams -Wl,-R$(PWD)/libs/myteams

all: $(NAME)

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ) $(SRC_MAIN) $(CFLAGS)

debug:
	gcc -g -o $(NAME) $(SRC) $(SRC_MAIN) $(CFLAGS)

clean:
	rm -f $(OBJ)
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

re:	fclean all

tests_run:
	gcc -o $(NAME_TEST) $(SRC_TEST) $(SRC) $(CFLAGS) -lcriterion --coverage -I ../tests/ -ftest-coverage -fprofile-arcs
