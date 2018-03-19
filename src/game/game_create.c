/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game.c
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

char **my_realloc_2d(char **map, char *line)
{
	size_t i = 0;
	char **new_map;

	for (; map && map[i] != NULL; i++);
	if ((new_map = malloc(sizeof(char *) * (i + 2))) == NULL)
		return (NULL);
	for (i = 0; map && map[i] != NULL; i++)
		new_map[i] = map[i];
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

char **save_file()
{
	char *str = get_next_line(0);
	char **file = NULL;

	for (int i = 0; str != NULL; i++) {
		file = my_realloc_2d(file, str);
		str = get_next_line(0);
	}
		return (file);
}

void take_start(game_t *game, char **file, int i)
{
	char **start;

	if (my_strncmp(file[i], "##start", 8) == 0) {
		start = str_to_tab(file[i + 1], " ");
		game->start->name = start[0];
		game->start->x = atoi(start[1]);
		game->start->y = atoi(start[2]);
	}
}

void take_end(game_t *game, char **file, int i)
{
	char **end;

	if (my_strncmp(file[i], "##end", 6) == 0) {
		end = str_to_tab(file[i + 1], " ");
		game->end->name = end[0];
		game->end->x = atoi(end[1]);
		game->end->y = atoi(end[2]);
	}
}

void take_rooms(game_t *game, char **file, int i) // if i re"use" this function
{
	char **room;
	static int j = 0;

	room = str_to_tab(file[i], " ");
	if (room[0] != NULL && room[1] != NULL && room[2] != NULL) {
		game->room[j].name = room[0];
		game->room[j].x = atoi(room[1]);
		game->room[j].y = atoi(room[2]);
		j++;
	}
}

bool take_info(game_t *game, char **file) // i must do parsing
{
	game->nb_ant = atoi(file[0]);
	for (int i = 0; file[i] != NULL; i++) {
		take_start(game, file, i);
		take_end(game, file, i);
		take_rooms(game, file, i);
	}
}

int count_rooms(char **file)
{
	int j = 0;
	char **room;

	for (int i = 0; file[i] != NULL; i++) {
		room = str_to_tab(file[i], " ");
		room[0] != NULL && room[1] != NULL && room[2] != NULL ? j++ : 0;
	}
	return (j);
}

game_t game_create(void)
{
	game_t game;
	char **file = save_file();

	game.start = malloc(sizeof(room_t));//why pointer
	game.end = malloc(sizeof(room_t));
	game.room = malloc(sizeof(room_t) * count_rooms(file));
	take_info(&game, file);
	for (int j = 0; j < count_rooms(file); j++)//tmp
		printf("nb_room %d|name :%s|x : %d|y : %d\n", count_rooms(file), game.room[j].name, game.room[j].x, game.room[j].y);//tmp
	for (int i = 0; file[i] != NULL; i++) //tmp
		printf("%s\n", file[i]); //tmp
	return (game);
}
