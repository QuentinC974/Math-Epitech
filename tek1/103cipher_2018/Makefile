##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for my_printf
##

SRC	=	cipher.c	\
		calculs.c	\
		usage.c		\
		matrix.c

OBJ	=	$(SRC:.c=.o) $(SRC_MAIN:.c=.o)

OBJ_TEST=	$(SRC:.c=.o) $(SRC_TEST:.c=.o)

NAME	=	103cipher

CFLAGS	=	-g -Iinclude -lm -W -Wall -Wextra -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f vg*

fclean:	clean
	rm -f $(NAME)

re:	fclean all
