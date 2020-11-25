#include "ft_printf.h"

/*
   0 1 2 3 4 5 6 7
   c s p d i u x X
 */

const char	*print_str_classic(const char *str, int *nb_char)
{
	char		*buf;
	const char	*save;
	int		i;

	i = 0;
	save = str;
	while(*str && *str != '%')
	{
		str++;
		i++;
	}
	buf = ft_substr(save, 0, i);
	if (!buf)
		return (NULL);
	ft_putstr(buf);
	free(buf);
	(*nb_char)+=i;
	return (str);
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int			ft_min(int a, int b)
{
	if (a == -1)
		return (b);
	if (a < b)
		return (a);
	return (b);
}
