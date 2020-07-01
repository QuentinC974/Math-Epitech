##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## CPD10ysk01
##

SRC	=	209.cpp

TEST	= tests/test.c

MAIN = main.cpp

OBJ	=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

OBJ_TEST=	$(SRC:.cpp=.o) $(TEST:.cpp=.o)



NAME	=	209poll

UNIT_TEST   =	unit_tests

CFLAGS	=	-W -Wall -Wextra

FDFLAGS	=	$(CFLAGS) -lcriterion --coverage 

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:
		g++ -o $(UNIT_TEST) $(SRC) $(TEST) $(FDFLAGS)
		./unit_tests
clean:
		rm -f $(OBJ)
		rm -rf	*.gc*

fclean:	clean
		rm -f $(NAME)
		rm -f $(UNIT_TEST)

re: fclean all


.PHONY:		all tests_run clean fclean re