##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile Arcade-sdl2
##

NAME	= arcade_sdl2.so

TARGET	= ../../lib/$(NAME)

SRC		= sdl2.cpp

OBJ 	= $(SRC:.cpp=.o)

CXX		= g++

CXXFLAGS	= -I../../include/ -Wall -fPIC -Wextra `sdl2-config --cflags --libs` -lSDL2_ttf

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
