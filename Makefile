##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SOLVER_DIR	=	cd solver/

GENERATOR_DIR	=	cd generator/

all:
	$(SOLVER_DIR) && $(MAKE) && cd ..
	$(GENERATOR_DIR) && $(MAKE) && cd ..

clean:
	$(SOLVER_DIR) && $(MAKE) clean && cd ..
	$(GENERATOR_DIR) && $(MAKE) clean && cd ..

fclean:		clean
	$(SOLVER_DIR) && $(MAKE) fclean && cd ..
	$(GENERATOR_DIR) && $(MAKE) fclean && cd ..

debug: fclean
	$(SOLVER_DIR) && $(MAKE) debug && cd ..
	$(GENERATOR_DIR) && $(MAKE) debug && cd ..

re:		fclean all

.PHONY:		all clean fclean re
