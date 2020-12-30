/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:46:14 by lle-briq          #+#    #+#             */
/*   Updated: 2020/12/30 15:17:52 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptoa(unsigned long ptr, int size)
{
	char	*res;
	char	*base;
	int		i;

	base = "0123456789abcdef";
	res = malloc((size + 1)*sizeof(char));
	if (!res)
		return (NULL);
	res[size] = '\0';
	i = size;
	while (--i > 1)
	{
		res[i] = base[ptr % 16];
		ptr = ptr / 16;
	}
	res[0] = '0';
	res[1] = 'x';
	return (res);
}

int	size_ptr(unsigned long ptr, int prec)
{
	int		i;

	i = 0;
	if (ptr == 0)
		return (ft_max(1, prec) + 2);
	while (ptr > 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (ft_max(i, prec) + 2);
}
