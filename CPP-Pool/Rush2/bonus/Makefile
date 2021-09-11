##
## EPITECH PROJECT, 2021
## CPPD06
## File description:
## Makefile
##

SRC		=		src/Object/Object.cpp 			\
				src/Object/Toy.cpp				\
				src/Object/Teddy.cpp 			\
				src/Object/LittlePony.cpp 		\
				src/Object/Wrap.cpp		 		\
				src/Object/Box.cpp 				\
				src/Object/GiftPaper.cpp 		\
				src/Factory/PapaXmasTable.cpp   \
				src/Factory/PapaXmasConveyorBelt.cpp \
				src/Factory/PapaXmasElf.cpp 	\
				src/Factory/ConveyorBeltRand.cpp \
				src/Factory/TableRand.cpp 		\
				src/Sock/Server/Server.cpp 		\
				src/Factory/MagicalCarpet.cpp   \

SRC_MAIN	=	src/main.cpp \

SRCS	=		src/main_santa.cpp 						\
				src/Santa/Santa.cpp 					\
				src/Sock/Client/Client.cpp 		\

SRCT	=		src/UnitTests/MyUnitTests.cpp

SRC_TEST	=	test/TestToy.cpp \
				test/TestTed.cpp \
				test/TestPony.cpp \
				test/TestWrap.cpp \
				test/TestElf.cpp \


OBJ		=	$(SRC:.cpp=.o)


OBJS		=	$(SRCS:.cpp=.o)

NAME	=		a.out

NAMES	=		santa

NAME_TEST	=	unit_test

FLAGS	=		-W -Wall -Wextra -I./include/ -lpthread -std=c++14 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:	$(NAME)

$(NAME):
		g++ -o $(NAME) $(SRC_MAIN) $(SRC) $(FLAGS)
		#g++ -o $(NAMES) $(SRCS) $(SRC) $(FLAGS)

clean:
		rm -f $(OBJ)
		find . -type f \(  -name "*~" -o -name "#*#" \) -delete
		find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

fclean:	clean
		rm -f $(NAME)
		rm -f vgcore.*
		rm -f $(NAME_TEST)

re: fclean all

tests_run:
	g++ -o $(NAME_TEST) $(SRC_TEST) $(SRC) -lcriterion --coverage $(FLAGS)
	find . -type f -name "test*.gcno" -delete
	find . -type f -name "test*.gcda" -delete
	./$(NAME_TEST)

run:
	g++ -g -o $(NAME) $(SRC_MAIN) $(SRC) $(FLAGS) -Ofast
	./a.out

valgrind: fclean
	g++ -g -o $(NAME) $(SRC_MAIN) $(SRC) $(FLAGS)
	valgrind --track-origins=yes ./$(NAME) gift.xml
	#--leak-check=full