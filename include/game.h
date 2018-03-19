/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game.h
*/

#ifndef GAME_H_
#define GAME_H_

#include "room.h"

typedef struct game_s {
	size_t start;
	size_t end;
	room_t *room;
} game_t;

game_t game_create(void);

#endif
