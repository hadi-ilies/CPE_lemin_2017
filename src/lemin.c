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

path_t *add_path(path_t *path, room_t *room)
{
	path_t *new_path = malloc(sizeof(path_t));

	if (new_path == NULL)
		return (NULL);
	new_path->room = room;
	new_path->next = path;
	return (new_path);
}

path_t *remove_path(path_t *path)
{
	path_t *new_path = NULL;

	if (path == NULL)
		return (NULL);
	new_path = path->next;
	free(path);
	return (new_path);
}

path_t *get_shorter_path(game_t *game, room_t *room, path_t *path)
{
	path = add_path(path, room);
	if (room == game->end)
		return (path);
	for (size_t i = 0; i < room->nb_next; i++) {
		if (room_in_path(room->next[i], path))
			continue;
		printf("%s : %s\n", room->name, room->next[i]->name);
		path = get_shorter_path(game, room->next[i], path);
		if (path->room == game->end)
			return (path);
	}
	path = remove_path(path);
	return (path);
}

void aff_path(path_t *path)
{
	if (path == NULL)
		return;
	aff_path(path->next);
	printf("plath : %s\n", path->room->name);
}

void path_destroy(path_t *path)
{
	if (path == NULL)
		return;
	path_destroy(path->next);
	free(path);
}

int lemin(game_t *game)
{
	path_t *path = NULL;

	path = get_shorter_path(game, game->start, path);
	aff_path(path);
	path_destroy(path);
	return (0);
}
