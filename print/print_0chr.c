#include "ft_printf.h"

int		print_0chr(t_print param, va_list args)
{
	int		c;
	char	*to_print;
	int		size;
	int		i;
	
	c = va_arg(args, int);
	size = (param.field > 0) ? param.field : 1;
	to_print = malloc((size + 1) * sizeof(char));
	if (!to_print)
		return (0);
	i = -1;
	while (++i < size)
		to_print[i] = ' ';
	if (param.align)
		to_print[0] = (unsigned char)c;
	else
		to_print[size - 1] = (unsigned char)c;
	to_print[size] = '\0';
	ft_putstr(to_print);
	free(to_print);
	return (size);
}
