/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** path.h
*/

#ifndef PATH_H_
#define PATH_H_

#include "room.h"

typedef struct path_s {
	room_t *room;
	struct path_s *next;
} path_t;

#endif
