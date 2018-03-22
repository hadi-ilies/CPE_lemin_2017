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
	for (int i = 0; nb_ants[i] != '\0'; i++)
		if (nb_ants[i] < '0' || nb_ants[i] > '9')
			return (false);
	return (true);
}
