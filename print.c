#include "ft_printf.h"

/*
   0 1 2 3 4 5 6 7
   c s p d i u x X
 */

int		print_chr0(t_print param, va_list args)
{
	printf("\n--- Je suis un char ---");
	print_param_useful(param);
	(void)args;
	return (1);
}

int		print_str1(t_print param, va_list args)
{
	printf("\n--- Je suis une string ---");
	print_param_useful(param);
	(void)args;
	return (1);
}

int		print_ptr2(t_print param, va_list args)
{
	printf("\n--- Je suis un pointeur ---");
	print_param_useful(param);
	(void)args;
	return (1);
}

int		print_dbl3(t_print param, va_list args)
{
	printf("\n--- Je suis un double ---");
	print_param_useful(param);
	(void)args;
	return (1);
}

int		print_int4(t_print param, va_list args)
{
	printf("\n--- Je suis un int ---");
	print_param_useful(param);
	(void)args;
	return (1);
}

int		print_uns5(t_print param, va_list args)
{
	printf("\n--- Je suis un unsigned int ---");
	print_param_useful(param);
	(void)args;
	return (1);
}

int		print_hex6(t_print param, va_list args)
{
	printf("\n--- Je suis un int en hexa ---");
	print_param_useful(param);
	(void)args;
	return (1);
}

int		print_heX7(t_print param, va_list args)
{
	printf("\n--- Je suis un int en HEXA ---");
	print_param_useful(param);
	(void)args;
	return (1);
}

/*
 * 0 1 2 3 4 5 6 7
 * c s p d i u x X
 */

void	print_param(t_print param, va_list args, int *nb_char)
{
	int	(*print_fun[8])(t_print, va_list);

	print_fun[0] = &print_chr0;
	print_fun[1] = &print_str1;
	print_fun[2] = &print_ptr2;
	print_fun[3] = &print_dbl3;
	print_fun[4] = &print_int4;
	print_fun[5] = &print_uns5;
	print_fun[6] = &print_hex6;
	print_fun[7] = &print_heX7;
	*nb_char += (print_fun[param.type])(param, args);
}
