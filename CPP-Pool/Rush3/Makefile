##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =           src/main.cpp                                    \
                src/modules/Time.cpp                            \
                src/modules/AMonitorModule.cpp                  \
                src/display/AMonitorDisplay.cpp                  \
                src/modules/Hostname.cpp                        \
                src/modules/System.cpp                          \
                src/modules/Uptime.cpp                          \
                src/modules/Username.cpp                        \
                src/modules/Processor.cpp                       \
                src/modules/Networking.cpp                      \
                src/modules/Memory.cpp                          \
                src/modules/Data/RamData.cpp                    \
                src/modules/Data/NetworkData.cpp                \
                src/sfml/loop.cpp                               \
                src/sfml/display.cpp                            \
                src/modules/Data/ProcessorData.cpp              \
				src/display/ncurses/modules/ANCursesModules.cpp	\
				src/display/ncurses/modules/TextModule.cpp		\
				src/display/ncurses/modules/BarModule.cpp		\
				src/display/ncurses/modules/MemoryModule.cpp	\
				src/display/ncurses/modules/NetWorkModule.cpp	\
				src/display/ncurses/window/NCursesWindow.cpp	\
				src/display/ncurses/window/NCursesDrawer.cpp	\


NAME =          my_gkrellm

CXX =           g++

CXXFLAGS =      -g  -W -Wall -Wextra -I./include/ -std=c++14

LDFLAGS =       -lncurses -lsfml-graphics -lsfml-window -lsfml-system

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX)  -o $(NAME) $(OBJ) $(LDFLAGS)

add_flag:
	clear
	clear

valgrind: fclean add_flag $(NAME)
	valgrind --track-origins=yes --show-leak-kinds=definite ./$(NAME) -g
#--leak-check=full
run: fclean add_flag $(NAME)
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
