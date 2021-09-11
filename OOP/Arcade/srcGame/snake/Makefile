##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile Arcade-snake
##

NAME	= arcade_nibbler.so

TARGET	= ../../lib/$(NAME)

SRC		= snake.cpp

OBJ 	= $(SRC:.cpp=.o)

CXX		= g++

CXXFLAGS	= -I../../include/ -Wall -fPIC -Wextra

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
