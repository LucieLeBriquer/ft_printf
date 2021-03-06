/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbtostr2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:14:48 by lle-briq          #+#    #+#             */
/*   Updated: 2020/12/30 15:18:47 by lle-briq         ###   ########.fr       */
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

char	*ft_utoct(unsigned int n)
{
	char	*res;
	char	*base;
	int		i;
	int		l;

	l = itoa_size(n, 1, 8);
	base = "01234567";
	res = malloc((l + 1)*sizeof(char));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n == 0)
		res[0] = '0';
	i = l - 1;
	while (i >= 0)
	{
		res[i] = base[n % 8];
		n = n / 8;
		i--;
	}
	return (res);
}
