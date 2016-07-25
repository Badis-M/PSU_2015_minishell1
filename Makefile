##
## Makefile for Makefile in /home/merakc_b/test/training/Makefile
## 
## Made by badis merakchi
## Login   <merakc_b@epitech.net>
## 
## Started on  Mon Nov 23 14:51:26 2015 badis merakchi
## Last update Sun Jan 24 23:29:53 2016 Badis Merakchi
##

SRC	=	minishell.c \
		get_next_line.c \
		my_str_to_wordtab.c \
		utils.c

NAME	=	mysh

CC	=	gcc

CFLAGS	=	-Wextra -Wall -pedantic -g

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)


$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all
