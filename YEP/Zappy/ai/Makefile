##
## EPITECH PROJECT, 2019
## project
## File description:
## Makefile
##

SRC	=	src/main.cpp 			\
		src/ai.cpp				\
		src/utils.cpp			\
		src/commands.cpp		\
		src/strategies.cpp		\
		src/movement.cpp		\
		src/workflow.cpp		\
		src/level.cpp		\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	zappy_ai

CXXFLAGS	=	-Wall -lboost_system -lm -g -O4 -lpthread

all:	$(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS)

debug:
	g++ -g -o $(NAME) $(SRC) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

clear:
	clear

kill:
	-pkill zappy_server
	-pkill zappy_gui
	-fuser -k -n tcp 4242

dovalgrind: kill
	cd .. && gnome-terminal --window -t ZAPPY_SERVER  -- bash -c './zappy_server -p 4242 -x 10 -y 10 -n team1 team2 team3 -c 2 -f 7 ; sleep 60'
	sleep 1
	cd .. && gnome-terminal --window -t ZAPPY_GUI     		   -- ./zappy_gui -h 127.0.0.1 -p 4242
	-valgrind --track-origins=yes ./zappy_ai  -h 127.0.0.1 -p 4242 -n team1 | cat -e
	#-./zappy_ai  -h 127.0.0.1 -p 4242 -n team1 | cat -e
	make fclean

valgrind: clear fclean
	make all -j 16
	make dovalgrind


dovalgrind2: kill
	cd .. && gnome-terminal --window -t ZAPPY_SERVER  -- bash -c './zappy_test_server -p 4242 -x 10 -y 10 -n team1 team2 team3 -c 2 -f 240 &> servlog ; sleep 60'
	sleep 1
	cd .. && gnome-terminal --window -t ZAPPY_GUI     		   -- ./zappy_gui -h 127.0.0.1 -p 4242
	-valgrind --track-origins=yes ./zappy_ai  -h 127.0.0.1 -p 4242 -n team1 | cat -e
	#-./zappy_ai  -h 127.0.0.1 -p 4242 -n team1 | cat -e
	make fclean

valgrind2: clear fclean
	make all -j 16
	make dovalgrind2
