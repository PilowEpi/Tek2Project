##
## EPITECH PROJECT, 2021
## zappy
## File description:
## Makefile
##

all:
	cd build && cmake .. && make -j 16

run: all
	cd build && ./zappy_gui

re:
	rm -rf build/*
	make all

clean:
	rm -rf build/zappy_gui

fclean:
	rm -rf build/*

valgrind: all
	cd build && valgrind --track-origins=yes  ./zappy_gui
	#cd build && valgrind ./zappy_gui

callgrind: all
	rm -f build/*.callgrind
	-cd build && valgrind --tool=callgrind ./zappy_gui
	-kcachegrind build/callgrind.*