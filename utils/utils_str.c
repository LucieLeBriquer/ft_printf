/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:59:13 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/27 20:12:23 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_str_right(char **to_print, char *str, t_print param, int size)
{
	int		len;
	int		to_keep;
	int		i;

	len = ft_strlen(str);
	to_keep = ft_min(param.precision, len);
	i = -1;
	(*to_print)[size - 1] = '\0';
	while (++i < to_keep)
		(*to_print)[size - to_keep + i - 1] = str[i];
	i = -1;
	while (++i < size - to_keep - 1)
		(*to_print)[i] = ' ';
}

static void	fill_str_left(char **to_print, char *str, t_print param, int size)
{
	int		len;
	int		to_keep;
	int		i;

	len = ft_strlen(str);
	to_keep = ft_min(param.precision, len);
	(*to_print)[size - 1] = '\0';
	i = to_keep - 1;
	while (++i < size - 1)
		(*to_print)[i] = ' ';
	i = -1;
	while (++i < to_keep)
		(*to_print)[i] = str[i];
}

void		fill_str_s(char **to_print, char *str, t_print param, int size)
{
	if (param.align)
		fill_str_left(to_print, str, param, size);
	else
		fill_str_right(to_print, str, param, size);
}
