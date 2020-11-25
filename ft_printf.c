#include "ft_printf.h"

/*
   0 1 2 3 4 5 6 7
   c s p d i u x X
 */

int			ft_printf(const char *str, ...)
{
	va_list args;
	t_print	param;
	int		nb_char;

	if (!is_all_coherent(str))
		return (0);
	va_start(args, str);
	nb_char = 0;
	while (*str)
	{
		if (*str != '%')
			str = print_str_classic(str, &nb_char);
		else
		{
			str++;
			init_param(&param);
			str = parse_param(&param, str, args);
			if (!str)
				return (0);
			print_param(param, args, &nb_char);
		}
	}
	return (nb_char);
}

int		main()
{
	ft_printf("[%-2s]\n", "bonjour");
	printf("[%-2s]\n", "bonjour");
	ft_printf("[%-10.5s]\n", "ohayo");
	printf("[%-10.5s]\n", "ohayo");
	ft_printf("[%1.2s]\n", "plop");
	printf("[%1.2s]\n", "plop");
	return (0);
}
