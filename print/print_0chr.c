/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_0chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:23:35 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/27 19:32:30 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_0chr(t_print param, va_list args)
{
	char	c[2];
	char	*to_print;
	int		size;
	
	c[0] = va_arg(args, int);
	c[1] = '\0';
	size = (param.field > 0) ? param.field : 1;
	to_print = malloc((size + 1) * sizeof(char));
	if (!to_print)
		return (0);
	fill_str_s(&to_print, c, param, size + 1);
	to_print[size] = '\0';
	ft_putstr(to_print);
	free(to_print);
	return (size);
}
