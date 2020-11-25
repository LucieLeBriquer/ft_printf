#include "ft_printf.h"

int		print_2ptr(t_print param, va_list args)
{
	printf("\n--- Je suis un pointeur ---");
	print_param_useful(param);
	(void)args;
	return (1);
}
