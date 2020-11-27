/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3dbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:51:09 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/27 15:48:01 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_str_right_p(char **to_print, char *nb, t_print param, int size)
{
	int		len;
	int		sg;
	int		i;

	len = ft_strlen(nb);
	sg = (nb[0] == '-');
	i = len;
	while (--i >= sg)
		(*to_print)[size - len + i - 1] = nb[i];
	i = size - param.precision - 1;
	if (sg)
		(*to_print)[i - 1] = '-';
	i--;
	while (++i < size + sg - len - 1)
		(*to_print)[i] = '0';
	i = -1;
	while (++i < size - param.precision - 1 - sg)
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
	int		sg;
	int		i;
	int		j;
	int		nb_zero;

	len = ft_strlen(nb);
	sg = (nb[0] == '-');
	if (sg)
		(*to_print)[0] = '-';
	nb_zero = param.precision - len + sg;
	i = sg - 1;
	while (nb_zero > 0 && ++i < nb_zero + sg)
		(*to_print)[i] = '0';
	j = -1;
	while (++j + sg < len)
		(*to_print)[i + j] = nb[sg + j];
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
	int		sg;

	i = -1;
	sg = (nb[0] == '-');
	len = ft_strlen(nb);
	while (++i < size - 1)
		(*to_print)[i] = '0';
	i = -1;
	if (sg)
	{
		(*to_print)[0] = '-';
		i++;
	}
	while (++i <= len - sg)
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

	prec = (int)ft_strlen(nb) - (nb[0] == '-');
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

static int	size_tot(t_print param, char *nb_itoa)
{
	int		max1;
	int		max2;

	max1 = ft_max(param.field, param.precision + (nb_itoa[0] == '-'));
	max2 = ft_max(max1, ft_strlen(nb_itoa));
	return (max2 + 1);
}

int		print_3dbl(t_print param, va_list args)
{
	int		nb;
	int		size;
	char	*nb_itoa;
	char	*to_print;

	nb = va_arg(args, int);
	nb_itoa = ft_itoa(nb);
	size = size_tot(param, nb_itoa);
	to_print = malloc(size * sizeof(char));
	if (!to_print)
		return (0);
	fill_str(&to_print, nb_itoa, param, size);
	free(nb_itoa);
	ft_putstr(to_print);
	free(to_print);
	return (size - 1);
}
