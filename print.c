#include "ft_printf.h"

/*
   0 1 2 3 4 5 6 7
   c s p d i u x X
 */

void	print_param(t_print param, va_list args, int *nb_char)
{
	int	(*print_fun[8])(t_print, va_list);

	print_fun[0] = &print_0chr;
	print_fun[1] = &print_1str;
	print_fun[2] = &print_2ptr;
	print_fun[3] = &print_3dbl;
	print_fun[4] = &print_4int;
	print_fun[5] = &print_5uns;
	print_fun[6] = &print_6hex;
	print_fun[7] = &print_7heX;
	*nb_char += (print_fun[param.type])(param, args);
}
