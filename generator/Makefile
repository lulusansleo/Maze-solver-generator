##
## EPITECH PROJECT, 2022
## my_defender Makefile
## File description:
## compiles and builds lib and the source files runs unit tests
##

NAME		=	generator

SRC			=	source/main_file.c\
				source/second_file.c\
				functions/functions.c

CPPFLAGS 	=	-I./include

OBJ			=	$(SRC:.c=.o)

all: compil

compil : $(OBJ)
	gcc -o $(NAME) $(OBJ)

debug:	CFLAGS += -g3 -Wall -Wextra
debug:	re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all makelib clean fclean re
