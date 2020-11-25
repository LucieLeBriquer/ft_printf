/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:59:13 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/25 20:44:12 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_str_right(char **to_print, char *str, t_print param, int size)
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

void	fill_str_left(char **to_print, char *str, t_print param, int size)
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

void	fill_str(char **to_print, char *str, t_print param, int size)
{
	if (param.align)
		fill_str_left(to_print, str, param, size);
	else
		fill_str_right(to_print, str, param, size);
}

int		print_1str(t_print param, va_list args)
{
	char	*str;
	char	*to_print;
	int		size;
	int		len;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	size = ft_max(param.field, len) + 1;
	to_print = malloc(size * sizeof(char));
	if (!to_print)
		return (0);
	fill_str(&to_print, str, param, size);
	ft_putstr(to_print);
	free(to_print);
	return (1);
}
