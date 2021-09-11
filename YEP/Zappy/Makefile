##
## EPITECH PROJECT, 2021
## zappy
## File description:
## Makefile
##

all: zappy_server zappy_gui zappy_ai

clean:
	$(MAKE) -C server/ clean
	$(MAKE) -C gui/ clean
	$(MAKE) -C ai/ clean

fclean:
	$(MAKE) -C server/ fclean
	$(MAKE) -C gui/ fclean
	$(MAKE) -C ai/ fclean
	$(RM) zappy_gui
	$(RM) zappy_server
	$(RM) zappy_ai

re: fclean all

zappy_server:
	$(MAKE) -C server/
	mv server/zappy_server zappy_server

zappy_gui:
	$(MAKE) -C gui/
	mv gui/build/zappy_gui zappy_gui

zappy_ai:
	$(MAKE) -C ai/
	mv ai/zappy_ai zappy_ai

.PHONY: all clean fclean re zappy_server zappy_gui zappy_ai