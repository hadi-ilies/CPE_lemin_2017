/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** my_fprintf.c
*/

#include <stdarg.h>
#include <unistd.h>

size_t my_putchar(int fd, const char c)
{
	return (write(fd, &c, 1));
}

size_t my_putstr(int fd, const char *str)
{
	size_t i = 0;

	for (; str[i] != '\0'; i++);
	return (write(fd, str, i));
}

size_t my_putnbr(int fd, int nb)
{
	size_t size = 0;

	nb < 0 ? size += my_putchar(fd, '-') : 0;
	nb < 0 ? nb = -nb : 0;
	nb / 10 > 0 ? size += my_putnbr(fd, nb / 10) : 0;
	size += my_putchar(fd, nb % 10 + '0');
	return (size);
}

size_t print_var(int fd, va_list arg, const char type)
{
	size_t size = 0;

	type == 's' ? size += my_putstr(fd, va_arg(arg, char *)) : 0;
	type == 'd' ? size += my_putnbr(fd, va_arg(arg, int)) : 0;
	return (size);
}

size_t my_fprintf(int fd, const char *str, ...)
{
	va_list arg;
	size_t size = 0;

	va_start(arg, str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '%') {
			size += print_var(fd, arg, str[i + 1]);
			i++;
		}
		else
			size += write(fd, str + i, 1);
	}
	va_end(arg);
	return (size);
}
