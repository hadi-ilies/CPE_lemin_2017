/*
** EPITECH PROJECT, 2018
** take info
** File description:
** take info
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

void take_rooms(game_t *game, char **file, int i)
{
	char **room;

	room = str_to_tab(file[i], " ");
	if (room[0] != NULL && room[1] != NULL && room[2] != NULL) {
		game->room[game->nb_room].name = room[0];
		game->room[game->nb_room].x = atoi(room[1]);
		game->room[game->nb_room].y = atoi(room[2]);
		if (my_strncmp(file[i - 1], START, my_strlen(START)) == 0)
			game->start = &game->room[game->nb_room];
		else if (my_strncmp(file[i - 1], END, my_strlen(END)) == 0)
			game->end = &game->room[game->nb_room];
		game->nb_room++;
	} else
		free(room[0]);
	for (int j = 1; room[j] != NULL; j++)
		free(room[j]);
	free(room);
}

bool take_info(game_t *game, char **file)
{
	game->nb_ant = atoi(file[0]);
	for (int i = 0; file[i] != NULL; i++)
		take_rooms(game, file, i);
	return (false);
}

int count_rooms(char **file)
{
	int j = 0;
	char **room;

	for (int i = 0; file[i] != NULL; i++) {
		room = str_to_tab(file[i], " ");
		room[0] != NULL && room[1] != NULL && room[2] != NULL ? j++ : 0;
		for (int j = 0; room[j] != NULL; j++)
			free(room[j]);
		free(room);
	}
	return (j);
}
