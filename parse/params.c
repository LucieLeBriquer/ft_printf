#include "ft_printf.h"

void		init_param(t_print *param)
{
	param->align = 0;
	param->zero = 0;
	param->field = -1;
	param->precision = -1;
	param->type = -1;
}

const char	*parse_align_zero(t_print *param, const char *str)
{
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			param->align = 1;
		else
			param->zero = 1;
		str++;
	}
	return (str);
}

void		negative_stars(t_print *param)
{
	if (param->field < 0)
	{
		param->field = (-1) * (param->field);
		param->align = 1;
	}
	if (param->precision < 0)
		param->precision = -1;
}

const char	*parse_param(t_print *param, const char *str, va_list args)
{
	int		nb;

	param->type = is_type(*str);
	str = parse_align_zero(param, str);
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
		if (param->precision == 1)
			param->precision = nb;
		else
			param->field = nb;
		param->type = is_type(*str);
	}
	negative_stars(param);
	return (++str);
}
