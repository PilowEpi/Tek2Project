##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile Arcade
##

CXX		= g++

## Core Project

CORE_SRC 	=	src/main.cpp	\
				src/arcade_init.cpp	\
				src/arcade.cpp \
				src/arcade_menu.cpp

CORE_OBJ	= $(CORE_SRC:.cpp=.o)

CORE_NAME 	= arcade

CXXFLAGS	= -I./include/ -Wall -Wextra -std=c++17 -ldl

LIBDIR		= lib/


all:	core graphicals games

debug:	fclean debug_core
	$(MAKE) --no-print-directory -C srcGraphical debug
	$(MAKE) --no-print-directory -C srcGame debug

core:	$(CORE_OBJ)
	$(CXX) -o $(CORE_NAME) $(CORE_OBJ) $(CXXFLAGS)

libfld:
	mkdir -p $(LIBDIR)

doc:
	doxygen doc/Doxyfile

.PHONY: doc

## Graphical Rule

graphicals: libfld
	$(MAKE) --no-print-directory -C srcGraphical

## Game Rule

games: libfld
	$(MAKE) --no-print-directory -C srcGame

## Rule

debug_core: CXXFLAGS += -g
debug_core: core

clean_own:
	$(RM) -f $(CORE_OBJ)

clean: clean_own
	$(MAKE) --no-print-directory -C srcGraphical clean
	$(MAKE) --no-print-directory -C srcGame clean

fclean: clean_own
	$(RM) -f $(CORE_NAME)
	$(MAKE) --no-print-directory -C srcGraphical fclean
	$(MAKE) --no-print-directory -C srcGame fclean

re: fclean all

genval:
	valgrind --suppressions=v.sup --gen-suppressions=all --leak-check=full --show-leak-kinds=all ./arcade lib/arcade_ncurses.so

val:
	valgrind --leak-check=full --show-leak-kinds=all ./arcade lib/arcade_ncurses.so

vals:
	valgrind -s --suppressions=v.sup --leak-check=full --show-leak-kinds=all ./arcade lib/arcade_ncurses.so

valslog:
	valgrind -s --suppressions=v.sup --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log.v ./arcade lib/arcade_ncurses.so

valslogall:
	valgrind -s --suppressions=v.sup --leak-check=full --show-leak-kinds=all --track-origins=yes ./arcade lib/arcade_ncurses.so 2> logall.v
