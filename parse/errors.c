/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:24:37 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/28 18:25:21 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_type(char c)
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
	if (c == '%')
		return (8);
	return (-1);
}

int			is_coherent(const char *str)
{
	int		size;
	int		type;

	size = 0;
	while ((*str == '-' || *str == '0') && size++)
		str++;
	if (*str == '*' && size++)
		str++;
	else
	{
		while (*str && ft_isdigit(*str) && size++)
			str++;
	}
	if (*str == '.' && size++)
		str++;
	if (*str == '*' && size++)
		str++;
	else
	{
		while (*str && ft_isdigit(*str) && size++)
			str++;
	}
	type = is_type(*str);
	return ((type == 8) + (type >= 0) - 1);
}

int			is_all_coherent(const char *str)
{
	int		type;

	while (*str)
	{
		if (*str != '%')
			str++;
		else
		{
			str++;
			type = is_coherent(str);
			if (type < 0)
				return (0);
			if (type == 1)
				str++;
		}
	}
	return (1);
}
