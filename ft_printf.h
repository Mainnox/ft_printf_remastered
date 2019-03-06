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
	va_list		ap;
	t_extra		*extra;
}				t_printf;

void	ft_putchar_printf(t_printf *handle);
void	ft_flags_printf(t_printf *handle);
int		ft_atoi_printf(t_printf *handle);
int		ft_nbrlen(unsigned long long nb, char signe, unsigned int ba);
void	ft_set_moins(t_printf *handle);
void	ft_set_blanck(t_printf *handle);
void	ft_set_precision(t_printf *handle);
void	ft_set_zero(t_printf *handle);
void	ft_set_width(t_printf *handle);
void	ft_set_plus(t_printf *handle);
void	ft_set_hastag(t_printf *handle);
void	ft_set_star(t_printf *handle);
void	ft_set_size(t_printf *handle);
int		ft_printf(const char *str, ...);
void	ft_print_printf(t_printf *handle);
void	ft_print_c(t_printf *handle, unsigned *c);
void	ft_print_while(t_printf *handle, int len, char c);
int		ft_strlen(char *str);
void	ft_print_str(t_printf *handle, char *str);
void	ft_print_s(t_printf *handle, unsigned *s);
void	ft_print_signed(t_printf *handle, int base);
void	ft_print_unsigned(t_printf *handle, unsigned int base);
void	ft_print_X(t_printf *handle, unsigned int base);
void	ft_print_hastag(t_printf *handle, char c, unsigned int ba);
int		ft_cal_nbdisplay(t_printf *handle, int len, char c, unsigned int ba, unsigned long long nb);
int		ft_cal_p(t_printf *handle, int len, char c, unsigned int ba);
int		ft_cal_nbdisplay_signed(t_printf *handle, int len, char signe);
void	ft_print_signe(t_printf *handle, char signe);
void	ft_print_pc(t_printf *handle);
void	ft_print_char(t_printf *handle, char c);
void	ft_print_char2( char c);
#endif
