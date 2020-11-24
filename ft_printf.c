#include <stdarg.h>
#include "libft.h"

#include <stdio.h>

typedef struct
{
	int		align;
	int		zero;
	int		field;
	int		precision;
	int		type;
}	t_print;

void	init_param(t_print *param)
{
	param->align = 0;
	param->zero = 0;
	param->field = 0;
	param->precision = 0;
	param->type = -1;
}

void	print_param(t_print p)
{
	printf("\n--- param ---\n");
	printf("\talign = %d", p.align);
	printf("\tzero = %d", p.zero);
	printf("\tfield = %d", p.field);
	printf("\tprecision = %d", p.precision);
	printf("\ttype = %d\n", p.type);
}

/*
   0 1 2 3 4 5 6 7
   c s p d i u x X
 */

int		is_type(char c)
{
	if (c == 'c')
		return (0);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (2);
	if (c == 'd')
		return (3);
	if (c == 'i')
		return (4);
	if (c == 'u')
		return (5);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	return (-1);
}

int			is_coherent(const char *str)
{
	if (*str == '-')
		str++;
	if (*str == '0')
		str++;
	if (*str == '*')
		str++;
	else
	{
		while (*str && ft_isdigit(*str))
			str++;
	}
	if (*str == '.')
		str++;
	if (*str == '*')
		str++;
	else
	{
		while (*str && ft_isdigit(*str))
			str++;
	}
	return (is_type(*str));
}

const char	*fill_then_print(t_print *param, const char *str, va_list args)
{
	int		nb;

	param->type = is_type(*str);
	if (*str == '-' && str++)
		param->align = 1;
	if (*str == '0' && str++)
		param->zero = 1;
	while (param->type < 0)
	{
		if (*str == '.' && str++)
			param->precision = 1;
		if (*str == '*' && str++)
			nb = va_arg(args, int);
		else
			nb = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
		if (param->precision && (nb > 0))
			param->precision = nb;
		else if (nb > 0)
			param->field = nb;
		param->type = is_type(*str);
	}
	return (++str);
}

int		is_all_coherent(const char *str)
{
	while (*str)
	{
		if (*str != '%')
			str++;
		else
		{
			str++;
			if (is_coherent(str) < 0)
				return (0);
		}
	}
	return (1);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	t_print	param;

	if (!is_all_coherent(str))
	{
		ft_putstr("Format error\n");
		return (0);
	}
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			str++;
		}
		else
		{
			str++;
			init_param(&param);
			str = fill_then_print(&param, str, args);
			if (!str)
			{
				ft_putstr("Conversion error\n");
				return (-1);
			}
			print_param(param);
		}
	}
	return (1);
}

int		main()
{
	ft_printf("hello %02.*d my %s %0-124d", 200, 12, "blop");
	return (0);
}
