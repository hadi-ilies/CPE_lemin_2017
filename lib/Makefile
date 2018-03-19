##
## EPITECH PROJECT, 2017
## tetrus
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	my_strlen.c \
		my_printf.c \
		my_fprintf.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I../include
CFLAGS	+=	-W -Wall -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
