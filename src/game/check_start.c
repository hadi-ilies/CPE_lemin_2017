/*
** EPITECH PROJECT, 2018
** check_start
** File description:
** check_start
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

void display_error_links(char **file)
{
	my_printf("#number_of_ants\n");
	my_printf("%s\n", file[0]);
	my_printf("#rooms\n");
	for (int i = 1; file[i] != NULL; i++)
		my_printf("%s\n", file[i]);
	my_printf("#tunnels\n");
}

bool there_is_links(char **file)
{
	char **link = NULL;
	bool tmp = false;

	for (int i = 0; file[i] != NULL; i++) {
		link = str_to_tab(file[i], " \t");
		if (link[0] != NULL && link[1] == NULL
		&& count_bar(link[0]) == true)
			tmp = true;
		for (int j = 0; link[j] != NULL; j++)
			free(link[j]);
		free(link);
		if (tmp)
			return (true);
	}
	display_error_links(file);
	return (false);
}

void check_start_end_error_display(char **file)
{
	char **tmp = NULL;
	bool bol = 1;

	my_printf("#number_of_ants\n");
	my_printf("%s\n", file[0]);
	my_printf("#rooms\n");
	for (int i = 1; file[i] != NULL; i++) {
		tmp = str_to_tab(file[i], " \t");
		if (tmp[0] != NULL && tmp[1] == NULL
		&& count_bar(tmp[0]) == true && bol == 1) {
			return;
		} for (int j = 0; tmp[j] != NULL; j++)
			free(tmp[j]);
		free(tmp);
		my_printf("%s\n", file[i]);
	}
}

bool check_start(char **file)
{
	char **check_start = NULL;
	bool tmp = false;

	if (there_is_links(file) == false)
		return (false);
	for (int i = 0; file[i] != NULL; i++) {
		if (my_strncmp(file[i], START, my_strlen(START)) == 0) {
			check_start = str_to_tab(file[i + 1], " \t");
			if (check_start[0] != NULL && check_start[1] != NULL
			&& check_start[2] != NULL)
				tmp = true;
			for (int j = 0; check_start[j] != NULL; j++)
				free(check_start[j]);
			free(check_start);
			tmp == false ? check_start_end_error_display(file) : 0;
			return (tmp);
		}
	}
	check_start_end_error_display(file);
	return (false);
}

bool check_end(char **file)
{
	char **check_end = NULL;
	bool tmp = false;

	for (int i = 0; file[i] != NULL; i++) {
		if (my_strncmp(file[i], END, my_strlen(END)) == 0) {
			check_end = str_to_tab(file[i + 1], " \t");
				if (check_end[0] != NULL && check_end[1] != NULL
			&& check_end[2] != NULL)
				tmp = true;
			for (int j = 0; check_end[j] != NULL; j++)
				free(check_end[j]);
			free(check_end);
			tmp == false ? check_start_end_error_display(file) : 0;
			return (tmp);
		}
	}
	check_start_end_error_display(file);
	return (false);
}
