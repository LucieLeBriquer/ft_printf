/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_7heX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:51:09 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/28 18:06:13 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_7heX(t_print param, va_list args)
{
	unsigned	nb;
	int			size;
	char		*nb_utoX;
	char		*to_print;

	nb = (unsigned int)va_arg(args, int);
	nb_utoX = ft_utoxx(nb);
	if (nb == 0 && param.precision == 0)
		nb_utoX[0] = '\0';
	size = size_int(param, nb_utoX);
	to_print = malloc(size * sizeof(char));
	if (!to_print)
		return (0);
	fill_int(&to_print, nb_utoX, param, size);
	free(nb_utoX);
	ft_putstr(to_print);
	free(to_print);
	return (size - 1);
}
