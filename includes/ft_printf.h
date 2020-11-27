#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"

#include <stdio.h>

typedef struct
{
	int		align;
	int		zero;
	int		field;
	int		precision;
	int		type;
}			t_print;

int			ft_max(int a, int b);
int			ft_min(int a, int b);
void		init_param(t_print *param);
void		print_param_useful(t_print p);
int			is_type(char c);
int			is_coherent(const char *str);
const char	*parse_param(t_print *param, const char *str, va_list args);
int			is_all_coherent(const char *str);
const char	*print_str_classic(const char *str, int *nb_char);
void		print_param(t_print p, va_list args, int *nb_char);
int			ft_printf(const char *str, ...);
int			print_0chr(t_print param, va_list args);
int			print_1str(t_print param, va_list args);
int			print_2ptr(t_print param, va_list args);
int			print_3dbl(t_print param, va_list args);
int			print_4int(t_print param, va_list args);
int			print_5uns(t_print param, va_list args);
int			print_6hex(t_print param, va_list args);
int			print_7heX(t_print param, va_list args);

