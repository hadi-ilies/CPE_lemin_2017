/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** my_strlen.c
*/

#include "my.h"

ssize_t my_strlen(const char *str)
{
	ssize_t size;

	if (str == NULL)
		return (-1);
	for (size = 0; str[size] != '\0'; size++);
	return (size);
}
