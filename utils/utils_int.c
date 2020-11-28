/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:46:14 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/28 18:34:07 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_space(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	unsigned long long int	nb;
	short int				sg;

	nb = 0;
	while (*nptr && is_space(*nptr))
		nptr++;
	sg = 1 - 2 * (*nptr == '-');
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		nb = 10 * nb + (*nptr - '0');
		if (nb > (unsigned long long)(9223372036854775807 + (sg == -1)))
			return ((sg + 1) / (-2));
		nptr++;
	}
	return ((int)(sg * nb));
}

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int			ft_min(int a, int b)
{
	if (a == -1)
		return (b);
	if (a < b)
		return (a);
	return (b);
}
