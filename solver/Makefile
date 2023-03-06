##
## EPITECH PROJECT, 2022
## my_defender Makefile
## File description:
## compiles and builds lib and the source files runs unit tests
##

NAME		=	solver

CC 			= 	gcc

SRC			=	source/main_file.c\

CPPFLAGS 	=	-Wall -Wextra

LDFLAGS 	=	-L./lib/my -lmy

CFLAGS		=	-I./include

OBJ			=	$(SRC:.c=.o)

all: compil

compil : $(OBJ)
	gcc -o $(NAME) $(OBJ)

debug:	CFLAGS += -g3
debug:	re

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all makelib clean debug fclean re
