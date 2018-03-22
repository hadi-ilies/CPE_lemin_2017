/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *my_realloc(char *buf, size_t size)
{
	char *new_buf = malloc(sizeof(char) * size);
	bool end = false;

	if (new_buf == NULL)
		return (NULL);
	for (size_t i = 0; i < size; i++) {
		!end && buf[i] == '\0' ? end = true : 0;
		!end ? new_buf[i] = buf[i] : 0;
		end ? new_buf[i] = '\0' : 0;
	}
	free(buf);
	return (new_buf);
}

char *get_line_main(int fd)
{
	char *buf = malloc(sizeof(char) * 2);

	if (buf == NULL)
		return (NULL);
	for (size_t i = 0;; i++) {
		if (read(fd, &buf[i], 1) < 1) {
			free(buf);
			return (NULL);
		}
		buf[i + 1] = '\0';
		buf = my_realloc(buf, i + 3);
		if (buf == NULL)
			return (NULL);
		if (buf[i] == '\n') {
			buf[i] = '\0';
			return (buf);
		}
	}
}

char *get_next_line(int fd)
{
	char *line = get_line_main(fd);

	while (line && my_strlen(line) > 0 && line[my_strlen(line) - 1] == ' ')
		line[my_strlen(line) - 1] = '\0';
	return (line);
}
