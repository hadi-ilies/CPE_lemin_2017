/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** lemin.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "my.h"

void move_ant2(game_t *game, room_t **ant, size_t num, bool *tmp)
{
	size_t nb = ant[num]->nb_ant - 1;

	for (size_t i = 0; i < ant[num]->nb_next; i++) {
		bool cond1 = false;
		bool cond2 = ant[num]->next[i]->nb_ant == 0;

		cond1 = ant[num]->next[i]->var < ant[num]->var + nb;
		if ((cond1 && cond2) || ant[num]->next[i] == game->end) {
			ant[num]->nb_ant--;
			ant[num]->next[i]->nb_ant++;
			*tmp ? my_printf(" ") : 0;
			my_printf("P%d-%s", num + 1, ant[num]->next[i]->name);
			ant[num] = ant[num]->next[i];
			*tmp = true;
			break;
		}
	}
}

void move_ant(game_t *game, room_t **ant)
{
	bool tmp = true;

	while (tmp) {
		tmp = false;
		for (size_t i = 0; i < game->nb_ant; i++)
			ant[i] != game->end ? move_ant2(game, ant, i, &tmp) : 0;
		tmp ? my_printf("\n") : 0;
	}
}

void start_end(game_t *game)
{
	my_printf("#moves\n");
	for (size_t i = 0; i < game->nb_ant; i++)
		my_printf("P%d-%s\n", i + 1, game->end->name);
}

int lemin(game_t *game)
{
	room_t **ant;

	if (game->start->var == 2) {
		start_end(game);
		return (0);
	}
	ant = malloc(sizeof(room_t *) * game->nb_ant);
	if (ant == NULL)
		return (84);
	for (size_t i = 0; i < game->nb_ant; i++)
		ant[i] = game->start;
	for (size_t i = 0; i < game->nb_room; i++)
		game->room[i].nb_ant = 0;
	game->start->nb_ant = game->nb_ant;
	my_printf("#moves\n");
	move_ant(game, ant);
	free(ant);
	return (0);
}
