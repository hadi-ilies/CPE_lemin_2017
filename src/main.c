/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** main.c
*/

#include "prototype.h"

int main(int nb)
{
	if (nb == 1) {
		game_t game = game_create();

		if (game.room == NULL)
			return (84);
		return (lemin(&game));
	}
	else {
		game_t game;
		room_t *room1 = malloc(sizeof(room_t));
		room_t *room2 = malloc(sizeof(room_t));
		room_t *room3 = malloc(sizeof(room_t));

		room1->name = "1";
		room1->x = 5;
		room1->y = 0;

		room2->name = "2";
		room2->x = 10;
		room2->y = 5;

		room3->name = "3";
		room3->x = 0;
		room3->y = 5;

		room1->nb_next = 2;
		room1->next = malloc(sizeof(room_t) * room1->nb_next);
		room1->next[0] = room2;
		room1->next[1] = room3;

		room2->nb_next = 1;
		room2->next = malloc(sizeof(room_t) * room2->nb_next);
		room2->next[0] = room1;

		room3->nb_next = 1;
		room3->next = malloc(sizeof(room_t) * room3->nb_next);
		room3->next[0] = room1;

		game.start = room1;
		game.end = room3;
		lemin(&game);
		free(room1->next);
		free(room2->next);
		free(room3->next);
		free(room1);
		free(room2);
		free(room3);
		return (0);
	}
}
