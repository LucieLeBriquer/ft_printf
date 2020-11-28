/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:17:51 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/28 18:09:58 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*mem;
	size_t			s;
	size_t			i;

	s = nmemb * size;
	ptr = malloc(s);
	if (!ptr)
		return (NULL);
	mem = (unsigned char *)ptr;
	i = -1;
	while (++i < s)
		mem[i] = '\0';
	return (ptr);
}

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && i < start)
		i++;
	j = 0;
	while (s[i] && i - start < len)
	{
		j++;
		i++;
	}
	sub = ft_calloc(j + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = start;
	while (i - start < j)
	{
		sub[i - start] = s[i];
		i++;
	}
	return (sub);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	size_t	l;

	if (!s)
		return ;
	l = ft_strlen(s);
	write(1, s, l);
}
