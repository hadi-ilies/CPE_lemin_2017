/*
** EPITECH PROJECT, 2018
** take info
** File description:
** take info
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

bool check_x_y(char *c_x, char *c_y)
{
	for (int i = 0; c_x[i] != '\0'; i++)
		if (c_x[i] < '0' || c_x[i] > '9')
			return (false);
	for (int j = 0; c_y[j] != '\0'; j++)
		if (c_y[j] < '0' || c_y[j] > '9')
			return (false);
	return (true);
}

bool take_rooms(game_t *game, char **file, int i)
{
	char **room;

	room = str_to_tab(file[i], " \t");
	if (room[0] != NULL && room[1] != NULL && room[2] != NULL) {
		if (check_x_y(room[1], room[2]) == false)
			return (false);
		game->room[game->nb_room].name = room[0];
		game->room[game->nb_room].x = my_atoi(room[1]);
		game->room[game->nb_room].y = my_atoi(room[2]);
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
	return (true);
}

bool take_info(game_t *game, char **file)
{
	game->nb_ant = my_atoi(file[0]);
	for (int i = 0; file[i] != NULL; i++)
		if (take_rooms(game, file, i) == false)
			return (false);
	return (true);
}

int count_rooms(char **file)
{
	int j = 0;
	char **room;

	for (int i = 0; file[i] != NULL; i++) {
		room = str_to_tab(file[i], " \t");
		room[0] != NULL && room[1] != NULL && room[2] != NULL ? j++ : 0;
		for (int j = 0; room[j] != NULL; j++)
			free(room[j]);
		free(room);
	}
	return (j);
}
