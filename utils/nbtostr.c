/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbtostr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:14:48 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/28 23:13:09 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	itoa_size(unsigned int nb, short int sg, unsigned int base)
{
	if (nb < base)
		return (1 + (sg == -1));
	return (1 + itoa_size(nb / base, sg, base));
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	short int		sg;
	char			*res;
	int				i;
	int				l;

	sg = 1 - 2 * (n < 0);
	nb = sg * n;
	l = itoa_size(nb, sg, 10);
	res = malloc((l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n == 0)
		res[0] = '0';
	if (sg == -1)
		res[0] = '-';
	i = l - 1;
	while (i >= (sg == -1))
	{
		res[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (res);
}

char		*ft_utoa(unsigned int n)
{
	char			*res;
	int				i;
	int				l;

	l = itoa_size(n, 1, 10);
	res = malloc((l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n == 0)
		res[0] = '0';
	i = l - 1;
	while (i >= 0)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (res);
}

char		*ft_utox(unsigned int n)
{
	char	*res;
	char	*base;
	int		i;
	int		l;

	l = itoa_size(n, 1, 16);
	base = "0123456789abcdef";
	res = malloc((l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n == 0)
		res[0] = '0';
	i = l - 1;
	while (i >= 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	return (res);
}

char		*ft_utoxx(unsigned int n)
{
	char	*res;
	char	*base;
	int		i;
	int		l;

	l = itoa_size(n, 1, 16);
	base = "0123456789ABCDEF";
	res = malloc((l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n == 0)
		res[0] = '0';
	i = l - 1;
	while (i >= 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	return (res);
}
