/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game_error.c
*/

#include <unistd.h>
#include "game.h"

/*static bool pme(char *error_msg)
{
	size_t size = 0;

	for (; error_msg[size] != '\0'; size++);
	//write(STDERR_FILENO, error_msg, size);
	return (true);
	}*/

static bool pme(char *error_msg)
{
	(void)error_msg;
	return (true);
}

bool game_error(game_t *game)
{
	if (game == NULL)
		return (pme("game is NULL\n"));
	if (game->nb_ant <= 0)
		return (pme("game nb_ant is 0\n"));
	if (game->start == NULL)
		return (pme("game start is NULL\n"));
	if (game->end == NULL)
		return (pme("game end is NULL\n"));
	if (game->nb_room < 2)
		return (pme("game nb_room is less of 2\n"));
	if (game->room == NULL)
		return (pme("game room is NULL\n"));
	for (size_t i = 0; i < game->nb_room; i++)
		if (room_error(&game->room[i]))
			return (true);
	return (false);
}
