##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile NanoTekSpice
##

SRC		=	main.cpp \
			src/Nano/Nano.cpp	\
			src/Nano/CoreCommands.cpp \
			src/Nano/Core.cpp \
			src/Nano/Parser.cpp \
			src/Nano/ComponentFactory.cpp \
			src/Component/AComponent.cpp \
			src/Component/APin.cpp \
			src/Component/LogicGate.cpp \
			src/Component/Pin/Input.cpp	\
			src/Component/Pin/LoggerComponent.cpp \
			src/Component/Pin/Output.cpp \
			src/Component/Pin/True.cpp \
			src/Component/Pin/False.cpp \
			src/Component/Pin/Clock.cpp \
			src/Component/Chipset/2716Component.cpp	\
			src/Component/Chipset/4001Component.cpp	\
			src/Component/Chipset/4008Component.cpp \
			src/Component/Chipset/4011Component.cpp \
			src/Component/Chipset/4013Component.cpp \
			src/Component/Chipset/4017Component.cpp \
			src/Component/Chipset/4030Component.cpp \
			src/Component/Chipset/4040Component.cpp \
			src/Component/Chipset/4069Component.cpp \
			src/Component/Chipset/4071Component.cpp \
			src/Component/Chipset/4081Component.cpp \
			src/Component/Chipset/4094Component.cpp \
			src/Component/Chipset/4512Component.cpp \
			src/Component/Chipset/4514Component.cpp \

NAME	=	nanotekspice

CXXFLAGS	= -I./include/

CXX		= g++

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

valgrind: fclean
	clear
	$(CXX) -o $(NAME) $(SRC) $(CXXFLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) testFile/nts_single/4017_johnson.nts

testFunctional: all
	./test/testNTS.sh

fclean: clean
	$(RM) $(NAME)

re: fclean all