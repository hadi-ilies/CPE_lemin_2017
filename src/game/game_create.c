/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** game.c
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

char **my_realloc_2d(char **map, char *line)
{
	size_t i = 0;
	char **new_map;

	for (; map && map[i] != NULL; i++);
	if ((new_map = malloc(sizeof(char *) * (i + 2))) == NULL)
		return (NULL);
	for (i = 0; map && map[i] != NULL; i++)
		new_map[i] = map[i];
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

char **save_file()
{
	char *str = get_next_line(0);
	char **file = NULL;

	for (int i = 0; str != NULL; i++) {
		file = my_realloc_2d(file, str);
		str = get_next_line(0);
	}
		return (file);
}

game_t game_create(void)
{
	game_t game;
	char **file = save_file();

	for (int i = 0; file[i] != NULL; i++)
		printf("%s\n", file[i]);
	return (game);
}
