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
		if (my_strncmp(file[i - 1], START, my_strlen(START)) == 0)
			game->start = &game->room[game->nb_room];
		else if (my_strncmp(file[i - 1], END, my_strlen(END)) == 0)
			game->end = &game->room[game->nb_room];
		game->nb_room++;
	}
}

bool take_info(game_t *game, char **file) // i must do parsing
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
	}
	return (j);
}

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

bool check_room_exist(game_t *game, char **link)
{
	int exist1 = 0;
	int exist2 = 0;

	for (size_t i = 0; i < game->nb_room; i++) {
		if (my_strncmp(link[0], game->room[i].name, my_strlen(game->room[i].name)) == 0)
			exist1 = 1;
		if (my_strncmp(link[1], game->room[i].name, my_strlen(game->room[i].name)) == 0)
			exist2 = 1;
	} if (exist1 == 0 || exist2 == 0)
		return (false);
	return (true);
}

bool take_link(game_t *game, char **file)
{
	char **line;
	char **link;

	for (int i = 0; file[i]; i++) {
		line = str_to_tab(file[i], " ");
		if (line [0] != NULL && line[1] == NULL && count_bar(line[0]) == true) {
			link = str_to_tab(line[0], "-");
			if (check_room_exist(game, link) == false)
				return (false);
		}
	}
	return (true);
}

game_t game_create(void)
{
	game_t game = {.nb_room = 0};
	char **file = save_file();

	if (file == NULL)
		return (game);
	if ((game.room = malloc(sizeof(room_t) * count_rooms(file))) == NULL)
		return (game);
	if (parsing(file) == false)
		return (game);
	take_info(&game, file);
	if (parsing2(&game) == false)
		return (game);
	if (take_link(&game, file) == false)
		return (game);
	printf("sname :%s|sx : %d|sy : %d\n", game.start->name, game.start->x, game.start->y);//tmp
	printf("ename :%s|ex : %d|ey : %d\n", game.end->name, game.end->x, game.end->y);//tmp
	for (int j = 0; j < count_rooms(file); j++)//tmp
		printf("nb_room %d|name :%s|x : %d|y : %d\n", count_rooms(file), game.room[j].name, game.room[j].x, game.room[j].y);//tmp
	for (int i = 0; file[i] != NULL; i++) //tmp
		printf("%s\n", file[i]); //tmp
	return (game);
}
