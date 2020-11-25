#include "ft_printf.h"

/*
   0 1 2 3 4 5 6 7
   c s p d i u x X
 */

int			is_type(char c)
{
	if (c == 'c')
		return (0);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (2);
	if (c == 'd')
		return (3);
	if (c == 'i')
		return (4);
	if (c == 'u')
		return (5);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	return (-1);
}

int			is_coherent(const char *str)
{
	while (*str == '-')
		str++;
	while (*str == '0')
		str++;
	if (*str == '*')
		str++;
	else
	{
		while (*str && ft_isdigit(*str))
			str++;
	}
	if (*str == '.')
		str++;
	if (*str == '*')
		str++;
	else
	{
		while (*str && ft_isdigit(*str))
			str++;
	}
	return (is_type(*str));
}

int			is_all_coherent(const char *str)
{
	while (*str)
	{
		if (*str != '%')
			str++;
		else
		{
			str++;
			if (is_coherent(str) < 0)
				return (0);
		}
	}
	return (1);
}
