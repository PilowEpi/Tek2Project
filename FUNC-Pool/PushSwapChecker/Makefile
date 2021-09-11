##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakeFile Pushswap Checker
##

SRC		=		PushswapChecker.hs

OBJ		=		$(SRC:.hs=.o)
INT		=		$(SRC:.hs=.hi)

NAME	=		pushswap_checker

all:	$(NAME)

$(NAME): $(OBJ)
	ghc $(OBJ) -o $(NAME)

%.o: %.hs
	ghc -c $^ -o $@

clean:
	rm -f $(OBJ)
	rm -f $(INT)

fclean: clean
	rm -f $(NAME)

re: fclean all
