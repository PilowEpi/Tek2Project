##
## EPITECH PROJECT, 2019
## project
## File description:
## Makefile
##

SRC	=	src/accept.c \
		src/args.c \
		src/array.c \
		src/check.c \
		src/cmd.c \
		src/event.c \
		src/flush.c \
		src/g_event.c \
		src/handle.c \
		src/i_teams.c \
		src/init.c \
		src/loop.c \
		src/main.c \
		src/map.c \
		src/refill.c \
		src/register.c \
		src/spec.c \
		src/teams.c \
		src/time.c \
		src/player/env.c \
		src/player/misc.c \
		src/player/move.c \
		src/player/exc/angles.c \
		src/player/exc/egg.c \
		src/player/exc/env.c \
		src/player/exc/incant.c \
		src/player/exc/items.c \
		src/player/exc/misc.c \
		src/player/exc/move.c \
		src/player/exc/see.c \
		src/gui/broad/egg.c \
		src/gui/broad/incant.c \
		src/gui/broad/items.c \
		src/gui/broad/misc.c \
		src/gui/broad/map.c \
		src/gui/broad/move.c \
		src/gui/broad/player.c \
		src/gui/cmd/map.c \
		src/gui/cmd/player.c \
		src/gui/cmd/time.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

CFLAGS	=	-Iinclude -lm

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
