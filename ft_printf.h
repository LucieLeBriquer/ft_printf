#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

typedef struct
{
	int		align;
	int		zero;
	int		field;
	int		precision;
	int		type;
}			t_print;

void		init_param(t_print *param);
void		print_param_useful(t_print p);
void		print_param(t_print p, va_list args, int *nb_char);
int			is_type(char c);
int			is_coherent(const char *str);
const char	*parse_param(t_print *param, const char *str, va_list args);
int			is_all_coherent(const char *str);
const char	*print_str_classic(const char *str, int *nb_char);
int			ft_printf(const char *str, ...);
