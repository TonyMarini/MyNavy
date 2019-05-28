##
## EPITECH PROJECT, 2019
## PSU_navy_2018
## File description:
## Makefile
##

SRC		=		main.c						\
				error_verif/input_processing.c			\
				error_verif/display_help.c			\
				gameplay/start_player.c				\
				gameplay/load_map.c				\
				navy.c						\
				error_verif/action_error_two.c			\
				error_verif/action_error_one.c			\
				gameplay/load_ships.c				\
				error_verif/verification_file.c			\
				gameplay/connection_player.c			\
				gameplay/get_position_ship.c			\
				gameplay/enemy_map.c				\
				error_verif/signal_ctrl_d.c			\
				error_verif/check_lose.c			\
				gameplay/turn_player.c				\
				gameplay/capture_signal.c			\
				gameplay/signal_sending.c			\
				gameplay/command_player.c			\
				gameplay/translate_coord.c			\
				gameplay/hit_or_miss.c				\
				gameplay/check_turn.c				\
				error_verif/free_all.c				\
				gameplay/display_map.c

OBJ		=		$(SRC:.c=.o)

NAME		=		navy

CFLAGS		+=		-I./include/ -I./lib/include/

CCO		=		gcc -o

RM		=		rm -f

LIB		=		-L./lib -lmy

all:				$(NAME)

$(NAME):			$(OBJ)
				make -C ./lib
				$(CCO) $(NAME) $(OBJ) $(LIB) -g3
				make clean

clean:
				$(RM) $(OBJ)
				make clean -C ./lib

fclean:				clean
				$(RM) $(NAME)
				make fclean -C ./lib

re:				fclean all

.PHONY:				all clean fclean re
