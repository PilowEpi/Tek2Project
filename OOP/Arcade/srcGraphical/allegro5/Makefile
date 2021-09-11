##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile Arcade-sfml
##

NAME	= arcade_allegro5.so

TARGET	= ../../lib/$(NAME)

SRC		= allegro.cpp

OBJ 	= $(SRC:.cpp=.o)

CXX		= g++

CXXFLAGS	= -I../../include/ -Wall -fPIC -Wextra `pkg-config allegro-5 allegro_font-5 allegro_primitives-5 --libs --cflags`

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
