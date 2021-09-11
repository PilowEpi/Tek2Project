##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile Arcade-sdl2
##

NAME	= arcade_irrlicht.so

TARGET	= ../../lib/$(NAME)

SRC		= irrlicht.cpp

OBJ 	= $(SRC:.cpp=.o)

CXX		= g++

CXXFLAGS	= -I../../include/ -Wall -fPIC -Wextra -lIrrlicht

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -shared $(OBJ) -o $(NAME) $(CXXFLAGS)
	cp $(NAME) $(TARGET)

clean:
	$(RM) -f $(OBJ)
	$(RM) -f $(NAME)

fclean: clean
	$(RM) -f $(TARGET)

re: fclean all

debug: CXXFLAGS += -g
debug: all
