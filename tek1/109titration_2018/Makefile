##
## EPITECH PROJECT, 2018
## evalexpr
## File description:
## evalxpr
##

SRC	=	./109.c			\
		str_tab.c		\
		err.c			\
		usage.c			\
		isnum.c			\
		first_second.c	\
		third.c			\

SRC_TEST=	tests/test_109.c
SRC_MAIN=	main.c

OBJ	=	$(SRC:.c=.o) $(SRC_MAIN:.c=.o)

OBJ_TEST=	$(SRC:.c=.o) $(SRC_TEST:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I ./include -lm -g -g3 

LDFLAGS_TEST =	-lcriterion --coverage -I ./include

CC	=	gcc

NAME	=	109titration

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

tests_run:
		gcc -o unit_tests $(SRC) $(SRC_TEST) $(LDFLAGS_TEST) $(CFLAGS)
		./unit_tests
