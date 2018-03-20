/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** room_destroy.c
*/

#include <stdlib.h>
#include "room.h"

void room_destroy(room_t *room)
{
	free(room->name);
	free(room->next);
}
