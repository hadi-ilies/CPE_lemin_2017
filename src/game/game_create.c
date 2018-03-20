/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game.c
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

char **add_line(char **map, char *line)
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
		file = add_line(file, str);
		str = get_next_line(0);
	}
		return (file);
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
		if (my_strncmp(file[i - 1], "##start", 8) == 0)
			game->start = &game->room[j];
		if (my_strncmp(file[i - 1], "##end", 6) == 0)
			game->end = &game->room[j];
		j++;
	}
}

bool take_info(game_t *game, char **file) // i must do parsing
{
	game->nb_ant = atoi(file[0]);
	for (int i = 0; file[i] != NULL; i++) {
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

	game.room = malloc(sizeof(room_t) * count_rooms(file));
	take_info(&game, file);
	printf("sname :%s|sx : %d|sy : %d\n", game.start->name, game.start->x, game.start->y);//tmp
	printf("ename :%s|ex : %d|ey : %d\n", game.end->name, game.end->x, game.end->y);//tmp
	for (int j = 0; j < count_rooms(file); j++)//tmp
		printf("nb_room %d|name :%s|x : %d|y : %d\n", count_rooms(file), game.room[j].name, game.room[j].x, game.room[j].y);//tmp
	for (int i = 0; file[i] != NULL; i++) //tmp
		printf("%s\n", file[i]); //tmp
	return (game);
}
