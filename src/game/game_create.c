/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game.c
*/

#include <stdbool.h>
#include "game.h"
#include "my.h"

bool count_bar(char *link)
{
	size_t nb_bar = 0;

	for (int i = 0; link[i] != '\0'; i++)
		(link[i] == '-') ? nb_bar++ : 0;
	if (nb_bar == 1)
		return (true);
	else
		return (false);
}

void init_next(game_t *game)
{
	for (size_t i = 0; i < game->nb_room; i++) {
		game->room[i].var = 0;
		game->room[i].nb_next = 0;
		game->room[i].next = NULL;
	}
}

game_t game_create(void)
{
	game_t game = {.nb_room = 0};
	char **file = save_file();

	if (file == NULL)
		return (GAME_ERROR);
	if ((game.room = malloc(sizeof(room_t) * count_rooms(file))) == NULL)
		return (GAME_ERROR);
	if (parsing(file) == false || take_info(&game, file) == false)
		return (GAME_ERROR);
	if (parsing2(&game, file) == false)
		return (GAME_ERROR);
	if (parsing3(&game, file) == false)
		return (GAME_ERROR);
	init_next(&game);
	make_link(&game, file);
	if (game_set_var(&game, file) == false)
		return (GAME_ERROR);
	display_file(file);
	free_file(file);
	return (game);
}
