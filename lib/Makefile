##
## EPITECH PROJECT, 2017
## tetrus
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	my_strlen.c \
		my_printf.c \
		my_atoi.c \
		my_fprintf.c \
		my_strcmp.c \
		my_strncmp.c \
		get_next_line.c \
		str_to_tab.c \
		add_line.c

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
