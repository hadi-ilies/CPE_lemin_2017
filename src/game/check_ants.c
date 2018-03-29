/*
** EPITECH PROJECT, 2018
** check_ants
** File description:
** check_ant
*/

#include <stdbool.h>
#include "game.h"
#include "my.h"

bool check_ants(char *nb_ants)
{
	char **ants = NULL;

	ants = str_to_tab(nb_ants, " ");
	for (int i = 0; ants[0][i] != '\0'; i++) {
		if (ants[0][i] < '0' || ants[0][i] > '9') {
			my_printf("#number_of_ants\n");//ges
			my_printf("%s\n", ants[0]);//ges
			return (false);
		}
	} if (my_atoi(ants[0]) <= 0) {
		my_printf("#number_of_ants\n");//ges
		my_printf("%s\n", ants[0]);//ges
		return (false);
	} for (int i = 0; ants[i] != NULL; i++)
		free(ants[i]);
	free(ants);
	return (true);
}
