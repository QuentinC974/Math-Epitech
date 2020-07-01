##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## CPD10ysk01
##

SRC	=	202.cpp

TEST	=
OBJ	=	$(SRC:.cpp=.o)

NAME	=	202unsold

UNIT_TEST   =	unit_tests

CFLAGS	=	

FDFLAGS	=	$(CFLAGS) -lcriterion --coverage

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(LIB)

tests_run:
		g++ -o $(UNIT_TEST) $(TEST) $(LIB) $(FDFLAGS)
		./unit_tests

clean:
		rm -f $(OBJ)
		rm -rf	*.gc*

fclean:	clean
		rm -f $(NAME)
		rm -f $(UNIT_TEST)

re: fclean all


.PHONY:		all tests_run clean fclean re