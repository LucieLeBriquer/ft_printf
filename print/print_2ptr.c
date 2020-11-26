#include "ft_printf.h"

static void	fill_addr(unsigned long ptr, char **to_print, int start)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 14;
	while (--i > 1)
	{
		(*to_print)[i + start] = base[ptr % 16];
		ptr = ptr / 16;
	}
	(*to_print)[start + i] = 'x';
	(*to_print)[start + i - 1] = '0';
}

static void	init_print(char **to_print, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		(*to_print)[i] = ' ';
	(*to_print)[size] = '\0';
}

int			print_2ptr(t_print param, va_list args)
{
	unsigned long	ptr;
	char			*to_print;
	int				size;
	int				len;
	
	ptr = (unsigned long)va_arg(args, void *);
	len = 14;
	size = (param.field > len) ? param.field : len;
	to_print = malloc((size + 1) * sizeof(char));
	if (!to_print)
		return (0);
	init_print(&to_print, size);
	if (param.align)
		fill_addr(ptr, &to_print, 0);
	else
		fill_addr(ptr, &to_print, size - len);
	ft_putstr(to_print);
	free(to_print);
	return (size);
}
