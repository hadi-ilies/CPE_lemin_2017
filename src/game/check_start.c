/*
** EPITECH PROJECT, 2018
** check_start
** File description:
** check_start
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

bool check_start(char **file)
{
	char **check_start = NULL;

	for (int i = 0; file[i] != NULL; i++) {
		if (my_strncmp(file[i], START, my_strlen(START)) == 0) {
			check_start = str_to_tab(file[i + 1], " ");
			if (check_start[0] != NULL && check_start[1] != NULL
			&& check_start[2] != NULL)
				return (true);
			else
				return (false);
		}
	}
	return (false);
}

bool check_end(char **file)
{
	char **check_end = NULL;

	for (int i = 0; file[i] != NULL; i++) {
		if (my_strncmp(file[i], END, my_strlen(END)) == 0) {
			check_end = str_to_tab(file[i + 1], " ");
			if (check_end[0] != NULL && check_end[1] != NULL
			&& check_end[2] != NULL)
				return (true);
			else
				return (false);
		}
	}
	return (false);
}
