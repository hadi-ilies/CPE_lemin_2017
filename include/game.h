/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game.h
*/

#ifndef GAME_H_
#define GAME_H_

#include <stdbool.h>
#include "room.h"

typedef struct {
	size_t nb_ant;
	room_t *start;
	room_t *end;
	size_t nb_room;
	room_t *room;
} game_t;

game_t game_create(void);
void game_destroy(game_t *game);
bool game_error(game_t *game);

#endif
