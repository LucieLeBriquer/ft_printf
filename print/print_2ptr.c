/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:50:53 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/28 23:27:29 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_addr(unsigned long ptr, char **to_print, t_print param, int s)
{
	char	*base;

	base = "0123456789abcdef";
}
/*static void	fill_addr(unsigned long ptr, char **to_print, int start, int len)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = len;
	while (--i > 1)
	{
		(*to_print)[i + start] = base[ptr % 16];
		ptr = ptr / 16;
	}
	(*to_print)[start + i] = 'x';
	(*to_print)[start + i - 1] = '0';
}*/

static void	init_print(char **to_print, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		(*to_print)[i] = ' ';
	(*to_print)[size] = '\0';
}

static int	size_ptr(unsigned long ptr)
{
	if (ptr < 16)
		return (1);
	return (1 + size_ptr(ptr / 16));
}

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

int			print_2ptr(t_print param, va_list args)
{
	unsigned long	ptr;
	char			*to_print;
	int				size;
	int				len;

	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		return (print_ptr_null(param));
	len = size_ptr(ptr);
	size = ft_max(param.field, param.precision + 2);
	size = ft_max(size, len + 2);
	to_print = malloc((size + 1) * sizeof(char));
	if (!to_print)
		return (0);
	init_print(&to_print, size);
	if (param.align)
		fill_addr(ptr, &to_print, 0, len);
	else
		fill_addr(ptr, &to_print, size - len, len);
	write(1, to_print, size);
	free(to_print);
	return (size);
}
