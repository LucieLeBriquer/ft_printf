#include "ft_printf.h"

int		print_6hex(t_print param, va_list args)
{
	printf("\n--- Je suis un int en hexa ---");
	print_param_useful(param);
	(void)args;
	return (1);
}
