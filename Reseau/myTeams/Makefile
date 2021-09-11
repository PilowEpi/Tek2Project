##
## EPITECH PROJECT, 2019
## project
## File description:
## Makefile
##

SERVER	=	myteams_server
CLI		=	myteams_cli

CLI_TEST	=	unit_test_cli

all:
	$(MAKE) -C server --no-print-directory
	$(MAKE) -C cli --no-print-directory

	cp server/$(SERVER) $(SERVER)
	cp cli/$(CLI) $(CLI)

debug:
	$(MAKE) -C server debug --no-print-directory
	$(MAKE) -C cli debug --no-print-directory

	cp server/$(SERVER) $(SERVER)
	cp cli/$(CLI) $(CLI)

clean:
	$(MAKE) -C server clean --no-print-directory
	$(MAKE) -C cli clean --no-print-directory

fclean:	clean
	$(MAKE) -C server fclean --no-print-directory
	$(MAKE) -C cli fclean --no-print-directory

	rm -rf $(SERVER)
	rm -rf $(CLI)
	rm -rf $(CLI_TEST)
	rm -rf server.log
	rm -rf crash.log

re:	fclean all

tests_run:
	$(MAKE) -C cli tests_run --no-print-directory
	./cli/$(CLI_TEST)
	gcovr -r cli/ --exclude tests/
	gcovr -r cli/ -b --exclude tests/
## find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

run: re
	./start.sh