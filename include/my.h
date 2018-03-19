/*
** EPITECH PROJECT, 2018
** for_norme
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
int my_strncmp(const char *s1, const char *s2);
char *get_next_line(int fd);

#endif
