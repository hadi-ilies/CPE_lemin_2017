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

void ee2(room_t *room, size_t nb)
{
	for (size_t i = 0; i < room->nb_next; i++)
		if (room->next[i]->var == 0)
			room->next[i]->var = nb + 1;
}

void ee(game_t *game, size_t nb)
{
	for (size_t i = 0; i < game->nb_room; i++)
		if (game->room[i].var == nb)
			ee2(&game->room[i], nb);
}

void ee3(room_t *room, size_t nb)
{
	my_printf("P%d-%s", nb, room->name);
	my_printf("\n");
	for (size_t i = 0; i < room->nb_next; i++)
		if (room->next[i]->var < room->var) {
			ee3(room->next[i], nb);
			break;
		}
}

int lemin(game_t *game)
{
	my_printf("#moves\n");
	game->end->var = 1;
	for (size_t i = 1; i < game->nb_room; i++)
		ee(game, i);
	for (size_t i = 0; i < game->nb_ant; i++)
		ee3(game->start, i + 1);
	//aff(game);
	return (0);
}
