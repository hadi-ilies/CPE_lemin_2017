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

char **get_tab(room_t *room, char **tab)
{
	tab = add_line(tab, room->name);
	for (size_t i = 0; i < room->nb_next; i++)
		if (room->next[i]->var < room->var) {
			tab = get_tab(room->next[i], tab);
			break;
		}
	return (tab);
}

void print_path(game_t *game, char **tab)
{
	size_t len = 0;

	for (; tab[len] != NULL; len++);
	len--;
	for (size_t i = 1; i < len; i++)
		for (size_t j = 0; j < i; j++) {
			my_printf("P%d-%s", j + 1, tab[i - j]);
			my_printf("%s", j < i - 1 ? " " : "\n");
		}
	for (size_t i = 1; i <= game->nb_ant - len + 1; i++)
		for (size_t j = 0; j < len; j++) {
			my_printf("P%d-%s", i + j, tab[len - j]);
			my_printf("%s", j < len - 1 ? " " : "\n");
		}
	for (size_t i = 1; i < len; i++)
		for (size_t j = 0; j < len - i; j++) {
			my_printf("P%d", j + game->nb_ant + i - 2);
			my_printf("-%s", tab[len - j]);
			my_printf("%s", j < len - i - 1 ? " " : "\n");
		}
}

int lemin(game_t *game)
{
	char **tab = NULL;

	my_printf("#moves\n");
	game_set_var(game);
	tab = get_tab(game->start, tab);
	print_path(game, tab);
	free(tab);
	return (0);
}
