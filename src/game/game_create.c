/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game.c
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

char **save_file()
{
	char *str = get_next_line(0);
	char **file;

	for (int i = 0; str != NULL; i++) {
		file = malloc(sizeof(char *) * )

	}
		return (file);
}

game_t game_create(void)
{
	game_t game;
	char **file = save_file();

	//game.room = NULL;
	//if (game.nb_ant = atoi(get_next_line(0)) <= 0)
	//	return (game);
	//if (take_starter(&game) == false)
	//	return (game);
	return (game);
}
