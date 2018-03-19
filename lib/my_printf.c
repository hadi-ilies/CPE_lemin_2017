/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <unistd.h>

static size_t my_putchar(const char c)
{
	return (write(1, &c, 1));
}

static size_t my_putstr(const char *str)
{
	size_t i = 0;

	for (; str[i] != '\0'; i++);
	return (write(1, str, i));
}

static size_t my_putnbr(int nb)
{
	size_t size = 0;

	nb < 0 ? size += my_putchar('-') : 0;
	nb < 0 ? nb = -nb : 0;
	nb / 10 > 0 ? size += my_putnbr(nb / 10) : 0;
	size += my_putchar(nb % 10 + '0');
	return (size);
}

static size_t print_var(va_list arg, const char type)
{
	size_t size = 0;

	type == 's' ? size += my_putstr(va_arg(arg, char *)) : 0;
	type == 'd' ? size += my_putnbr(va_arg(arg, int)) : 0;
	return (size);
}

size_t my_printf(const char *str, ...)
{
	va_list arg;
	size_t size = 0;

	va_start(arg, str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '%') {
			size += print_var(arg, str[i + 1]);
			i++;
		}
		else
			size += write(1, str + i, 1);
	}
	va_end(arg);
	return (size);
}
