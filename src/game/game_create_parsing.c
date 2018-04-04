/*
** EPITECH PROJECT, 2018
** parsing
** File description:
** parsing
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

bool parsing(char **file)
{
	int start = 0;
	int end = 0;
	int i = 0;

	if (check_ants(file[0]) == false)
		return (false);
	if (check_start(file) == false || check_end(file) == false)
		return (false);
	for (i = 0; file[i] != NULL; i++) {
		my_strncmp(file[i], START, my_strlen(START)) == 0 ? start++ : 0;
		my_strncmp(file[i], END, my_strlen(END)) == 0 ? end++ : 0;
		if (start > 1 || end > 1)
			break;
	} if (start != 1 || end != 1) {
		display_error_more_start_end(file, i);
		return (false);
	} return (true);
}
bool check_name_and_coord(game_t *game, size_t *j)
{
	for (size_t i = 0; i < game->nb_room; i++) {
		if (i != *j) {
			if ((my_strcmp(game->room[*j].name, game->room[i].name) == 0)
			|| (game->room[*j].x == game->room[i].x
			&& game->room[*j].y == game->room[i].y)) {
				*j = i;
			return (false);
			}
		}
	}
	return (true);
}

bool parsing2(game_t *game, char **file)
{
	for (size_t j = 0; j < game->nb_room; j++)
		if (check_name_and_coord(game, &j) == false) {
			display_error_more_start_end(file,
						count_adds(file, j, game));
			return (false);
		}
	return (true);
}

bool parsing3(game_t *game, char **file)
{
	char **line;
	char **link;

	for (int i = 0; file[i]; i++) {
		line = str_to_tab(file[i], " \t");
		if (line [0] != NULL && line[1] == NULL
		&& count_bar(line[0]) == true) {
			link = str_to_tab(line[0], "-");
			if (ROOM_EXIST_DOUBLE) {
				display_error_link(file, i);
				return (false);
			} for (int j = 0; link[j] != NULL; j++)
				free(link[j]);
			free(link);
		} for (int j = 0; line[j] != NULL; j++)
			free(line[j]);
		free(line);
	}
	return (true);
}

bool check_room_exist(game_t *game, char **link)
{
	int exist1 = 0;
	int exist2 = 0;

	for (size_t i = 0; i < game->nb_room; i++) {
		if (my_strncmp(link[0], game->room[i].name,
			my_strlen(link[0])) == 0)
			exist1 = 1;
		if (my_strncmp(link[1], game->room[i].name,
				my_strlen(link[1])) == 0)
			exist2 = 1;
	} if (exist1 == 0 || exist2 == 0)
		return (false);
	return (true);
}
