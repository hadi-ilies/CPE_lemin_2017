/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** lemin.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "path.h"

bool room_in_path(room_t *room, path_t *path)
{
	path_t *tmp = path;

	while (tmp != NULL) {
		if (room == tmp->room)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

path_t *add_room_to_path(path_t *path, room_t *room)
{
	path_t *new_path = malloc(sizeof(path));

	if (new_path == NULL)
		return (NULL);
	new_path->room = room;
	new_path->next = path;
	return (new_path);
}

path_t *remove_room_to_path(path_t *path)
{
	path_t *new_path = NULL;

	if (path == NULL)
		return (NULL);
	new_path = path->next;
	free(path);
	return (new_path);
}

int get_shorter_path(game_t *game, room_t *room, path_t *path)
{
	for (size_t i = 0; i < room->nb_next; i++) {
		if (room_in_path(room, path))
			continue;
		if (room->next[i] == game->end)
			return (1);
		get_shorter_path(game, room->next[i], path);
	}
	return (0);
}

int lemin(game_t *game)
{
	path_t *path = NULL;

	get_shorter_path(game, game->start, path);
	return (0);
}
