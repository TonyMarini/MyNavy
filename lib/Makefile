##
## EPITECH PROJECT, 2018
##  | Makefile
## File description:
## Makefile to make a lib
##

NAME	=	libmy.a

SRC		=	useful_fonctions.c		\
			my_putnbr.c				\
			get_next_line.c			\
			my_getnbr.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean :
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
