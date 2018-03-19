##
## EPITECH PROJECT, 2017
## for_norme
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
		$(GAMEDIR)game_create.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-g

LDFLAGS	=	-L $(LIBDIR) -lmy

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@make re -C $(LIBDIR)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean	:
		@make clean -C $(LIBDIR)
		@rm -f $(OBJ)

fclean	:	clean
		@make fclean -C $(LIBDIR)
		@rm -f $(NAME)

re	:	fclean all
