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
ROOMDIR	=	$(SRCDIR)room/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)lemin.c \
		$(GAMEDIR)connect_rooms.c \
		$(GAMEDIR)check_ants.c \
		$(GAMEDIR)take_info.c \
		$(GAMEDIR)save_file.c \
		$(GAMEDIR)check_start.c \
		$(GAMEDIR)game_create.c \
		$(GAMEDIR)game_create_parsing.c \
		$(GAMEDIR)game_destroy.c \
		$(GAMEDIR)game_error.c \
		$(GAMEDIR)game_set_var.c \
		$(ROOMDIR)room_destroy.c \
		$(ROOMDIR)room_error.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-fdiagnostics-color
#CFLAGS	+=	-g

LDFLAGS	+=	-L $(LIBDIR) -lmy
#LDFLAGS	+=	-l c_graph_prog #tmp

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make re -C $(LIBDIR) --no-print-directory
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		cp $(NAME) test/

clean	:
		rm -f $(OBJ)
		make clean -C $(LIBDIR) --no-print-directory

fclean	:	clean
		rm -f $(NAME)
		make fclean -C $(LIBDIR) --no-print-directory

re	:	fclean all
