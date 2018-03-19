##
## EPITECH PROJECT, 2017
## lemin
## File description:
## Makefile
##

NAME	=	lem_in

CC	=	gcc

SRCDIR	=	src/
LIBDIR	=	lib/
GAMEDIR	=	$(SRCDIR)game/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)lemin.c \
		$(GAMEDIR)game_create.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-fdiagnostics-color
CFLAGS	+=	-g

LDFLAGS	=	-L $(LIBDIR) -lmy

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make re -C $(LIBDIR) --no-print-directory
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)
		make clean -C $(LIBDIR) --no-print-directory

fclean	:	clean
		rm -f $(NAME)
		make fclean -C $(LIBDIR) --no-print-directory

re	:	fclean all
