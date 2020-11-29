/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:50:53 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/29 15:28:04 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	print_ptr_null(t_print param)
{
	char	*nul;
	char	*to_print;
	int		size;

	nul = "(nil)";
	size = (param.field > 5) ? param.field : 5;
	to_print = malloc((size + 1) * sizeof(char));
	if (!to_print)
		return (0);
	fill_str_s(&to_print, nul, param, size + 1);
	write(1, to_print, size);
	free(to_print);
	return (size);
}

static void	fill_ptr(char **to_print, char *ptoa, t_print param, int size)
{
	int		len;
	int		i;

	len = ft_strlen(ptoa);
	(*to_print)[size] = '\0';
	i = -1;
	while (++i < size)
		(*to_print)[i] = ' ';
	if (param.align == 1)
	{
		i = -1; 
		while (++i < len)
			(*to_print)[i] = ptoa[i];
	}
	else
	{
		i = 0; 
		while (++i <= len)
			(*to_print)[size - i] = ptoa[len - i];
	}
}

int			print_2ptr(t_print param, va_list args)
{
	unsigned long	ptr;
	char			*to_print;
	char			*ptoa;
	int				size;
	int				len;

	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		return (print_ptr_null(param));
	len = size_ptr(ptr, param.precision);
	ptoa = ft_ptoa(ptr, len);
	if (!ptoa)
		return (0);
	size = ft_max(len, param.field);
	to_print = malloc((size + 1) * sizeof(char));
	if (!to_print)
		return (0);
	fill_ptr(&to_print, ptoa, param, size);
	free(ptoa);
	write(1, to_print, size);
	free(to_print);
	return (size);
}
