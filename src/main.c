/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** main.c
*/

#include "prototype.h"

int main(void)
{
	game_t game = game_create();

	if (game.nb_room < 2 || game.start == NULL || game.end == NULL || game.room == NULL)
		return (84);
	return (lemin(&game));
}
