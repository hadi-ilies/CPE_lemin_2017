/*
** EPITECH PROJECT, 2018
** check_start
** File description:
** check_start
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

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
	return (false);
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
			return (tmp);
		}
	}
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
			return (tmp);
		}
	}
	return (false);
}
