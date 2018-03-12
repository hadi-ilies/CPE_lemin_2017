##
## EPITECH PROJECT, 2017
## for_norme
## File description:
## Makefile
##

NAME	=	a.out

CC	=	gcc

SRCDIR	=	src/
LIBDIR	=	lib/

SRC	=	$(SRCDIR)main.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
