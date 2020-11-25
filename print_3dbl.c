#include "ft_printf.h"

int		print_3dbl(t_print param, va_list args)
{
	printf("\n--- Je suis un double ---");
	print_param_useful(param);
	(void)args;
	return (1);
}
