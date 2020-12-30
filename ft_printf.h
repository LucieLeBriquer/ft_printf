/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:37:17 by lle-briq          #+#    #+#             */
/*   Updated: 2020/12/30 15:22:43 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	int		align;
	int		zero;
	int		field;
	int		precision;
	int		type;
}			t_print;

typedef int	(*t_func)(t_print, va_list);

int			ft_atoi(const char *nptr);
int			ft_strlen(const char *s);
int			size_int(t_print param, char *nb_itoa);
int			size_ptr(unsigned long ptr, int prec);
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);
char		*ft_utox(unsigned int n);
char		*ft_utoxx(unsigned int n);
char		*ft_utoct(unsigned int n);
char		*ft_ptoa(unsigned long ptr, int size);
void		ft_putstr(char *s);
int			ft_isdigit(int c);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
void		init_param(t_print *param);
void		print_param_useful(t_print p);
int			is_type(char c);
const char	*parse_param(t_print *param, const char *str, va_list args);
int			is_all_coherent(const char *str);
const char	*print_str_classic(const char *str, int *nb_char);
void		print_param(t_print p, va_list args, int *nb_char);
int			ft_printf(const char *str, ...);
void		fill_str_s(char **to_print, char *str, t_print param, int size);
void		fill_int_right_p(char **to_print, char *nb, t_print par, int size);
void		fill_int_right(char **to_print, char *nb, int size);
void		fill_int_left_p(char **to_print, char *nb, t_print par, int size);
void		fill_int_left(char **to_print, char *nb, int size);
void		fill_int_zero(char **to_print, char *nb, int size);
void		fill_int_easy(char **to_print, char *nb, int size);
void		fill_int(char **to_print, char *nb, t_print param, int size);
int			print_0chr(t_print param, va_list args);
int			print_1str(t_print param, va_list args);
int			print_2ptr(t_print param, va_list args);
int			print_3dbl(t_print param, va_list args);
int			print_4int(t_print param, va_list args);
int			print_5uns(t_print param, va_list args);
int			print_6hex(t_print param, va_list args);
int			print_7hxx(t_print param, va_list args);
int			print_8pct(t_print param, va_list args);
int			print_9oct(t_print param, va_list args);

#endif
