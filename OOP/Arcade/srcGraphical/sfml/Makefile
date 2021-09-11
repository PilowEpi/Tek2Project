##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile Arcade-sfml
##

NAME	= arcade_sfml.so

TARGET	= ../../lib/$(NAME)

SRC		= sfml.cpp

OBJ 	= $(SRC:.cpp=.o)

CXX		= g++

CXXFLAGS	= -I../../include/ -Wall -fPIC -Wextra -lsfml-graphics -lsfml-window -lsfml-system

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
