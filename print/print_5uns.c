#include "ft_printf.h"

int		print_5uns(t_print param, va_list args)
{
	printf("\n--- Je suis un unsigned int ---");
	print_param_useful(param);
	(void)args;
	return (1);
}
