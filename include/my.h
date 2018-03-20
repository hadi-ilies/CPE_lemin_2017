/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE 1
#endif

size_t my_printf(const char *str, ...);
size_t my_fprintf(int fd, const char *str, ...);
ssize_t my_strlen(const char *str);
int my_strcmp(const char *a, const char *b);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *get_next_line(int fd);
char **str_to_tab(char *command, char *sep);

#endif
