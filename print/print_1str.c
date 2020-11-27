/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:59:13 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/27 18:42:08 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_tot(t_print param, int len)
{
	if (param.precision == -1 || param.precision >= len)
		return (ft_max(param.field, len) + 1);
	return (ft_max(param.precision, param.field) + 1);
}

int		print_1str(t_print param, va_list args)
{
	char	*str;
	char	*to_print;
	int		size;
	int		len;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	size = size_tot(param, len);
	to_print = malloc(size * sizeof(char));
	if (!to_print)
		return (0);
	fill_str_s(&to_print, str, param, size);
	ft_putstr(to_print);
	free(to_print);
	return (size - 1);
}
