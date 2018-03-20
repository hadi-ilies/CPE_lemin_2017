/*
** EPITECH PROJECT, 2018
** parsing
** File description:
** parsing
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

bool parsing(char **file) // i must update this function
{
	int start = 0;
	int end = 0;

	for (int i = 0; file[i] != NULL; i++) {
		my_strncmp(file[i], START, my_strlen(START)) == 0 ? start++ : 0;
		my_strncmp(file[i], END, my_strlen(END)) == 0 ? end++ : 0;
	} if (start != 1 || end != 1)
		return (false);
	return (true);
}

bool check_name_and_coord(game_t *game, size_t j)
{
	for (size_t i = 0; i < game->nb_room; i++)
		if ((my_strcmp(game->room[j].name, game->room[i].name) == 0 && i != j)
		    || (game->room[j].x == game->room[i].x
			&& game->room[j].y == game->room[i].y && i != j))
			return (false);
	return (true);
}

bool parsing2(game_t *game)
{
	for (size_t j = 0; j < game->nb_room; j++)
		if (check_name_and_coord(game, j) == false)
			return (false);
	return (true);
}
