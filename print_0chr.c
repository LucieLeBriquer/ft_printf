#include "ft_printf.h"

int		print_0chr(t_print param, va_list args)
{
	printf("\n--- Je suis un char ---");
	print_param_useful(param);
	(void)args;
	return (1);
}
