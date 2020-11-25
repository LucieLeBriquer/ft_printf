#include "ft_printf.h"

void		init_param(t_print *param)
{
	param->align = 0;
	param->zero = 0;
	param->field = -1;
	param->precision = -1;
	param->type = -1;
}

const char	*parse_param(t_print *param, const char *str, va_list args)
{
	int		nb;

	param->type = is_type(*str);
	while (*str == '-' && str++)
		param->align = 1;
	while (*str == '0' && str++)
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
		if (param->precision == 1 && (nb > 0))
			param->precision = nb;
		else if (nb > 0)
			param->field = nb;
		param->type = is_type(*str);
	}
	return (++str);
}

/*
 * mettre un while autour des - et des 0 pour gerer 0 avant et/ou apres
 *
 */
