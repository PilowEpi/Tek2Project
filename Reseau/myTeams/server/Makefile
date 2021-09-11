##
## EPITECH PROJECT, 2019
## project
## File description:
## Makefile
##

SRC	=	src/append.c	\
		src/auth.c		\
		src/broad.c		\
		src/c_init.c	\
		src/c_broad.c	\
		src/client.c	\
		src/cmd.c		\
		src/conn.c		\
		src/create.c	\
		src/exist.c		\
		src/guards.c	\
		src/info.c		\
		src/list.c		\
		src/login.c		\
		src/loop.c		\
		src/main.c		\
		src/parse.c		\
		src/private.c	\
		src/restore.c	\
		src/save.c		\
		src/save_teams.c\
		src/sub.c		\
		src/teams.c		\
		src/unsub.c		\
		src/use.c		\
		src/users.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	myteams_server

CFLAGS	=	-std=gnu11 -Iinclude -luuid -I../libs/myteams \
			-L../libs/myteams -lmyteams -Wl,-R$(PWD)/libs/myteams

all:	$(NAME)

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug:
	gcc -g -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
