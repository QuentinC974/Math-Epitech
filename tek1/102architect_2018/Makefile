##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for my_printf
##

SRC	=	architect_fonctions.c	\
		my_getnbr.c		\
		usage.c			\
		fct_102_architect.c	\
		matrix_float.c		\
		init_n_result.c

SRC_MAIN=	main.c

SRC_TEST=	##mets les fichier de tests ici

OBJ	=	$(SRC:.c=.o) $(SRC_MAIN:.c=.o)

OBJ_TEST=	$(SRC:.c=.o) $(SRC_TEST:.c=.o)

NAME	=	102architect

CFLAGS	=	-g -Iinclude -lm -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f vg*

fclean:	clean
	rm -f $(NAME)

re:	fclean all
