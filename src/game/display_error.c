/*
** EPITECH PROJECT, 2018
** display_erro
** File description:
** display_error
*/

#include "game.h"
#include "my.h"

int count_adds(char **file, int j, game_t *game)
{
	int k = 0;
	char **array;

	for (int i = 0; file[i] != NULL; i++) {
		array = str_to_tab(file[i], " \t");
		if (my_strcmp(array[0], game->room[j].name) == 0)
			break;
		k++;
	}
	return (k + 1);
}

void display_error_more_start_end(char **file, int j)
{
	my_printf("#number_of_ants\n");
	my_printf("%s\n", file[0]);
	my_printf("#rooms\n");
	for (int i = 1; i != j; i++)
		my_printf("%s\n", file[i]);
}

void display_error_link(char **file, int j)
{
	char **tmp = NULL;
	bool bol = 1;

	my_printf("#number_of_ants\n");
	my_printf("%s\n", file[0]);
	my_printf("#rooms\n");
	for (int i = 1; i != j + 1; i++) {
		tmp = str_to_tab(file[i], " \t");
		if (tmp[0] != NULL && tmp[1] == NULL
		&& count_bar(tmp[0]) == true && bol == 1) {
			my_printf("#tunnels\n");
			bol = 0;
		} for (int j = 0; tmp[j] != NULL; j++)
			free(tmp[j]);
		free(tmp);
		my_printf("%s\n", file[i]);
	}
}
