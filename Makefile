##
## Makefile for whaou in /home/benoit.pingris/delivery/Jeux
## 
## Made by benoit pingris
## Login   <benoit.pingris@epitech.net>
## 
## Started on  Thu Jun  8 19:20:59 2017 benoit pingris
## Last update Sun Jun 11 17:54:27 2017 benoit pingris
##

CC	=	gcc

NAME	=	jeux

SRC	=	srcs/main.c				\
		srcs/draw.c				\
		srcs/game.c				\
		srcs/error.c				\
		srcs/setup.c				\
		srcs/moves.c				\
		srcs/get_next_line/get_next_line.c	\
		srcs/useful/disp_err.c			\
		srcs/useful/showtab.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include -Wall -Wextra

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-network

clean	:
		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

