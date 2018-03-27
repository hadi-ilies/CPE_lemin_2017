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
/*#include <SFML/Graphics.h> //tmp

void aff(game_t *game)
{
	sfVideoMode mode = {800, 800, 32};
	sfRenderWindow *window;
	sfEvent event;
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVertex point = {.color = sfWhite};
	sfVertexArray *line = sfVertexArray_create();

	sfVertexArray_setPrimitiveType(line, sfLinesStrip);
	sfRectangleShape_setSize(rect, (sfVector2f){30, 30});
	window = sfRenderWindow_create(mode, "Aff", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, 10);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
			if (event.type == sfEvtKeyPressed)
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
		for (size_t i = 0; i < game->nb_room; i++) {
			sfRectangleShape_setPosition(rect, (sfVector2f){game->room[i].x * 20, game->room[i].y * 20});
			sfRenderWindow_drawRectangleShape(window, rect, NULL);
			for (size_t j = 0; j < game->room[i].nb_next; j++) {
				point.position.x = game->room[i].x * 20 + 15;
				point.position.y = game->room[i].y * 20 + 15;
				sfVertexArray_append(line, point);
				point.position.x = game->room[i].next[j]->x * 20 + 15;
				point.position.y = game->room[i].next[j]->y * 20 + 15;
				sfVertexArray_append(line, point);
				sfRenderWindow_drawVertexArray(window, line, NULL);
				sfVertexArray_clear(line);
			}
		}
		sfRenderWindow_display(window);
	}
	sfRectangleShape_destroy(rect);
	sfVertexArray_destroy(line);
	sfRenderWindow_destroy(window);
	}*/


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

void ee3(game_t *game, char **tab)
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
	game->end->var = 1;
	game_set_var(game);
	tab = get_tab(game->start, tab);
	for (size_t i = 0; tab[i] != NULL; i++)
		my_printf("path : %s\n", tab[i]);
	ee3(game, tab);
	free(tab);
	return (0);
}

/*
  P1-3
  P1-4 P2-3
  P1-0 P2-4 P3-3
  P2-0 P3-4 P4-3
  P3-0 P4-4 P5-3
  P4-0 P5-4 P6-3
  P5-0 P6-4 P7-3
  P6-0 P7-4 P8-3
  P7-0 P8-4 P9-3
  P8-0 P9-4
  P9-0
 */
