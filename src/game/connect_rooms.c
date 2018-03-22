/*
** EPITECH PROJECT, 2018
** connect_room
** File description:
** connect_room
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

int find_room(game_t *game, char *room)
{
	for (size_t i = 0; i < game->nb_room; i++)
		if (my_strcmp(game->room[i].name, room) == 0) {
			return (i);
		}
	return (0);
}

void linked_room(room_t *room1, room_t *room2)
{
	room_t **next1 = malloc(sizeof(room_t *) * (room1->nb_next + 1));
	room_t **next2 = malloc(sizeof(room_t *) * (room2->nb_next + 1));

	for (size_t i = 0; i < room1->nb_next; i++)
		next1[i] = room1->next[i];
	next1[room1->nb_next] = room2;
	for (size_t i = 0; i < room2->nb_next; i++)
		next2[i] = room2->next[i];
	next2[room2->nb_next] = room1;
	free(room1->next);
	room1->next = next1;
	free(room2->next);
	room2->next = next2;
	room1->nb_next += 1;
	room2->nb_next += 1;
}

void make_link(game_t *game, char **file)
{
	char **line;
	char **link;

	for (int i = 0; file[i]; i++) {
		line = str_to_tab(file[i], " \t");
		if (line [0] != NULL && line[1] == NULL && count_bar(line[0]) == true) {
			link = str_to_tab(line[0], "-");
			linked_room(&game->room[find_room(game, link[0])],
				&game->room[find_room(game, link[1])]);
			for (int j = 0; link[j] != NULL; j++)
				free(link[j]);
			free(link);
		}
		for (int j = 0; line[j] != NULL; j++)
			free(line[j]);
		free(line);
	}
}
