#include "ft_printf.h"

void        ft_set_moins(t_printf *handle)
{
	handle->extra->moins = 1;
	handle->index++;
}

void        ft_set_blanck(t_printf *handle)
{
    handle->index++;
	handle->extra->blanck = 1;
}

void        ft_set_precision(t_printf *handle)
{
    handle->index++;
    handle->extra->precision = ft_atoi_printf(handle);
	if (handle->str[handle->index] == '*')
	{
		handle->extra->precision = (int)va_arg(handle->ap, unsigned *);
		if (handle->extra->precision < 0)
			handle->extra->precision = -handle->extra->precision;
		handle->index++;
		return ;
	}
	if (handle->extra->precision != -4)
 	   handle->index += ft_nbrlen((unsigned long long)handle->extra->precision, 0, 10);
	if (handle->extra->precision == -4)
		handle->extra->precision = 0;
}

void        ft_set_zero(t_printf *handle)
{
    handle->index++;
	handle->extra->zero = 1;
}

void        ft_set_width(t_printf *handle)
{
    handle->extra->width = ft_atoi_printf(handle);
    handle->index += ft_nbrlen((unsigned long long)handle->extra->width, 0, 10);
}
