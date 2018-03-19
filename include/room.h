/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** room.h
*/

#ifndef ROOM_H_
#define ROOM_H_

#include <stddef.h>

typedef struct room_s {
	size_t id;
	int x;
	int y;
	size_t nb_next;
	struct room_s **next;
} room_t;

#endif
