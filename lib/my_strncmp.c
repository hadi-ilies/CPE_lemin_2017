/*
** EPITECH PROJECT, 2018
** strncmp
** File description:
** strncmp
*/

int my_strncmp(const char *s1, const char *s2, int n)
{
	for (int k = 0; k < n; k++) {
		if (s1[k] != s2[k])
			return (-1);
		if (s1[k] == '\0')
			return (0);
	}
	return (0);
}
