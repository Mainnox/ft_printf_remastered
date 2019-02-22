#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_extra
{
	int		moins;
	int		plus;
	int		hastag;
	int		precision;
	int		blanck;
	int		done;
	int		width;
	int		size;
	int		zero;
}				t_extra;

typedef struct	s_printf
{
	int			index;
	const char	*str;
	int			nbprint;
	t_extra		*extra;
}				t_printf;

// SUPPRIME LES TEST
void	ft_putstr_test(const char *str);
void	ft_putchar_test(char c);
//STP

void	ft_putchar_printf(t_printf *handle);
void	ft_flags_printf(t_printf *handle, va_list ap);
int		ft_atoi_printf(t_printf *handle);
int		ft_nbrlen(unsigned long long nb, char signe);
void	ft_set_moins(t_printf *handle);
void	ft_set_blanck(t_printf *handle);
void	ft_set_precision(t_printf *handle);
void	ft_set_zero(t_printf *handle);
void	ft_set_width(t_printf *handle);
void	ft_set_plus(t_printf *handle);
void	ft_set_hastag(t_printf *handle);
void	ft_set_star(t_printf *handle, va_list ap);
void	ft_set_size(t_printf *handle);
int		ft_printf(const char *str, ...);
#endif
