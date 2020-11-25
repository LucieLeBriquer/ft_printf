/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_7heX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:34:14 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/25 15:34:16 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_7heX(t_print param, va_list args)
{
	printf("\n--- Je suis un int en HEXA ---");
	print_param_useful(param);
	(void)args;
	return (1);
}
