/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** room_error.c
*/

#include <unistd.h>
#include "room.h"

static bool pme(char *error_msg)
{
	size_t size = 0;

	for (; error_msg[size] != '\0'; size++);
	write(STDERR_FILENO, error_msg, size);
	return (true);
}

bool room_error(room_t *room)
{
	if (room == NULL)
		return (pme("room is NULL\n"));
	if (room->nb_next > 0 && room->next == NULL)
		return (pme("room next tab is NULL\n"));
	if (room->nb_next == 0 && room->next != NULL)
		return (pme("room next tab is not NULL\n"));
	for (size_t i = 0; i < room->nb_next; i++)
		if (room->next[i] == NULL)
			return (pme("room next is NULL\n"));
	return (false);
}
