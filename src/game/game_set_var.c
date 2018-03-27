/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** game_set_var.c
*/

#include "game.h"

void game_set_var3(room_t *room, size_t nb)
{
	for (size_t i = 0; i < room->nb_next; i++)
		if (room->next[i]->var == 0)
			room->next[i]->var = nb + 1;
}

void game_set_var2(game_t *game, size_t nb)
{
	for (size_t i = 0; i < game->nb_room; i++)
		if (game->room[i].var == nb)
			game_set_var3(&game->room[i], nb);
}

bool game_set_var(game_t *game)
{
	for (size_t i = 1; i < game->nb_room; i++)
		game->room[i].var = 0;
	game->end->var = 1;
	for (size_t i = 1; i < game->nb_room; i++)
		game_set_var2(game, i);
	return (game->start->var ? true : false);
}
