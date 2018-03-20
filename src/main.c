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

	if (game_error(&game))
		return (84);
	lemin(&game);
	game_destroy(&game);
	return (0);
}
