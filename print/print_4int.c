#include "ft_printf.h"

int		print_4int(t_print param, va_list args)
{
	printf("\n--- Je suis un int ---");
	print_param_useful(param);
	(void)args;
	return (1);
}
