/*
** EPITECH PROJECT, 2018
** display_erro
** File description:
** display_error
*/

#include "game.h"
#include "my.h"

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
	for (int i = 1; i != j; i++) {
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
