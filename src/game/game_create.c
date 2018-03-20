/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game.c
*/

#include <stdio.h> // tmp
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

char *supr_comment(char *str)
{
	if (str == NULL)
		return (NULL);
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '#' && str[i + 1] == '#')
			i++;
		else if (str[i] == '#' && str[i + 1] != '#') {
			str[i] = '\0';
			return (str);
		}
	return (str);
}

char **save_file(void)
{
	char *str = NULL;
	char **file = NULL;

	do {
		str = get_next_line(0);
		if (str == NULL)
			return (file);
		str = supr_comment(str);
		file = add_line(file, str);
	} while (str != NULL);
	return (file);
}

void take_rooms(game_t *game, char **file, int i) // if i re"use" this function
{
	char **room;

	room = str_to_tab(file[i], " ");
	if (room[0] != NULL && room[1] != NULL && room[2] != NULL) {
		game->room[game->nb_room].name = room[0];
		game->room[game->nb_room].x = atoi(room[1]);
		game->room[game->nb_room].y = atoi(room[2]);
		if (my_strcmp(file[i - 1], "##start") == 0)
			game->start = &game->room[game->nb_room];
		else if (my_strcmp(file[i - 1], "##end") == 0)
			game->end = &game->room[game->nb_room];
		game->nb_room++;
	}
}

bool take_info(game_t *game, char **file) // i must do parsing
{
	game->nb_ant = atoi(file[0]);
	for (int i = 0; file[i] != NULL; i++) {
		take_rooms(game, file, i);
		//take_tunnels
	}
	return (false);
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
	game_t game = {.nb_room = 0};
	char **file = save_file();

	if (file == NULL)
		return (game);
	if ((game.room = malloc(sizeof(room_t) * count_rooms(file))) == NULL)
		return (game);
	take_info(&game, file);
	printf("sname :%s|sx : %d|sy : %d\n", game.start->name, game.start->x, game.start->y);//tmp
	printf("ename :%s|ex : %d|ey : %d\n", game.end->name, game.end->x, game.end->y);//tmp
	for (int j = 0; j < count_rooms(file); j++)//tmp
		printf("nb_room %d|name :%s|x : %d|y : %d\n", count_rooms(file), game.room[j].name, game.room[j].x, game.room[j].y);//tmp
	for (int i = 0; file[i] != NULL; i++) //tmp
		printf("%s\n", file[i]); //tmp
	return (game);
}
