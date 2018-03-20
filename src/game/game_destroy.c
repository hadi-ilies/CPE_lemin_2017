/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game_destroy.h
*/

#include <stdlib.h>
#include "game.h"

void game_destroy(game_t *game)
{
	for (size_t i = 0; i < game->nb_room; i++)
		room_destroy(&game->room[i]);
	free(game->room);
}
