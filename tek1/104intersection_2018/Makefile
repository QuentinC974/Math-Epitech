##
## EPITECH PROJECT, 2018
## evalexpr
## File description:
## evalxpr
##

SRC	=	./usage.c		\
		my_calc_of_cone.c	\
		sphere.c		\
		cylinder.c		\
		init.c

SRC_TEST=	tests/test_cone.c	\
		tests/test_err.c

SRC_MAIN=	main.c

OBJ	=	$(SRC:.c=.o) $(SRC_MAIN:.c=.o)

OBJ_TEST=	$(SRC:.c=.o) $(SRC_TEST:.c=.o)

LIB	= 	-L lib/my -lmy

CFLAGS	=	-W -Wall -Wextra -I ./include -lm

LDFLAGS_TEST = 	-I ./include -lcriterion --coverage -lm

CC	=	gcc

NAME	=	104intersection

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -rf $(OBJ)
		rm -rf $(OBJ_TEST)

fclean:		clean
		rm -rf $(NAME)

tests_run:
		gcc -o unit_tests $(SRC) $(SRC_TEST) $(LDFLAGS_TEST)
		./unit_tests

re:		fclean all
