/*
** EPITECH PROJECT, 2018
** save_file
** File description:
** save_file
*/

#include "stdbool.h"
#include "game.h"
#include "my.h"

char *supr_comment(char *str)
{
	if (str == NULL)
		return (NULL);
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '#' && str[i + 1] == '#')
			i++;
		else if (str[i] == '#' && str[i + 1] != '#') {
			str[i] = '\0';
			return (str);
		}
	return (str);
}

bool check_urandom(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < ' ' || str[i] > '~')
			return (false);
	return (true);
}

char **save_file(void)
{
	char *str = NULL;
	char **file = NULL;

	do {
		str = get_next_line(0);
		if (str == NULL || check_urandom(str) == false)
			return (file);
		if ((str[0] == '#' && str[1] != '#') || (
		my_strncmp(str, "##", 2) == 0
		&& my_strcmp(str + 2, "start") != 0
		&& my_strcmp(str + 2, "end") != 0))
			str = get_next_line(0);
		str = supr_comment(str);
		file = add_line(file, str);
	} while (str != NULL);
	return (file);
}

void display_file(char **file)
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
			my_printf("#tunnels\n");
			bol = 0;
		} for (int j = 0; tmp[j] != NULL; j++)
			free(tmp[j]);
		free(tmp);
		my_printf("%s\n", file[i]);
	}
}

void free_file(char **file)
{
	for (int i = 0; file[i] != NULL; i++)
		free(file[i]);
	free(file);
}
