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

	if (game.room == NULL)
		return (84);
	return (lemin(&game));
}
