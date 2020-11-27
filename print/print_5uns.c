/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_5uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:51:09 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/27 14:56:35 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_str_right_p(char **to_print, char *nb, t_print param, int size)
{
	int		len;
	int		i;

	len = ft_strlen(nb);
	i = -1;
	while (++i < len)
		(*to_print)[size - 2 + i - len] = nb[i];
	i = size - param.precision - 1;
	while (++i < size - len - 1)
		(*to_print)[i] = '0';
	i = -1;
	while (++i < size - param.precision - 1)
		(*to_print)[i] = ' ';
}

static void	fill_str_right(char **to_print, char *nb, int size)
{
	int		len;
	int		i;
	int		j;

	i = -1;
	while (++i < size)
		(*to_print)[i] = ' ';
	len = ft_strlen(nb);
	i = len;
	j = size - 1;
	while (--i >= 0 && --j >= 0)
		(*to_print)[j] = nb[i];
}

static void	fill_str_left_p(char **to_print, char *nb, t_print param, int size)
{
	int		len;
	int		i;
	int		j;
	int		nb_zero;

	len = ft_strlen(nb);
	nb_zero = param.precision - len;
	i = -1;
	while (nb_zero > 0 && ++i < nb_zero)
		(*to_print)[i] = '0';
	j = -1;
	while (++j < len)
		(*to_print)[i + j] = nb[j];
	while (i + j < size - 1)
		(*to_print)[i + j++] = ' ';
}

static void	fill_str_left(char **to_print, char *nb, int size)
{
	int		len;
	int		i;

	len = ft_strlen(nb);
	i = -1;
	while (++i < len)
		(*to_print)[i] = nb[i];
	while (i < size - 1)
		(*to_print)[i++] = ' ';
}

static void	fill_str_zero(char **to_print, char *nb, int size)
{
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(nb);
	while (++i < size - 1)
		(*to_print)[i] = '0';
	i = -1;
	while (++i <= len)
		(*to_print)[size - 1 - i] = nb[len - i];
}

static void	fill_str_easy(char **to_print, char *nb, int size)
{
	int		i;

	i = -1;
	while (++i < size - 1)
		(*to_print)[i] = nb[i];
}

static void	fill_str(char **to_print, char *nb, t_print param, int size)
{
	int		prec;

	prec = (int)ft_strlen(nb);
	if (param.align && param.precision > prec)
		fill_str_left_p(to_print, nb, param, size);
	else if (param.align)
		fill_str_left(to_print, nb, size);
	else if (param.precision > prec)
		fill_str_right_p(to_print, nb, param, size);
	else if (param.precision > 0)
		fill_str_right(to_print, nb, size);
	else if (param.zero && param.field > 0)
		fill_str_zero(to_print, nb, size);
	else
		fill_str_easy(to_print, nb, size);
	(*to_print)[size - 1] = '\0';
}

static int	size_tot(t_print param, char *nb_utoa)
{
	int		max1;
	int		max2;

	max1 = ft_max(param.field, param.precision);
	max2 = ft_max(max1, ft_strlen(nb_utoa));
	return (max2 + 1);
}

int		print_5uns(t_print param, va_list args)
{
	unsigned	nb;
	int			size;
	char		*nb_utoa;
	char		*to_print;

	nb = (unsigned int)va_arg(args, int);
	nb_utoa = ft_utoa(nb);
	size = size_tot(param, nb_utoa);
	to_print = malloc(size * sizeof(char));
	if (!to_print)
		return (0);
	fill_str(&to_print, nb_utoa, param, size);
	free(nb_utoa);
	ft_putstr(to_print);
	free(to_print);
	return (size - 1);
}
