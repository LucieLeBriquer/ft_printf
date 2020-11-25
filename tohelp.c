#include "ft_printf.h"

void		print_param_useful(t_print p)
{
	printf("\n\talign = %d", p.align);
	printf("\tzero = %d", p.zero);
	printf("\tfield = %d", p.field);
	printf("\tprecision = %d", p.precision);
	printf("\ttype = %d\n", p.type);
}

/*
   0 1 2 3 4 5 6 7
   c s p d i u x X
 */
