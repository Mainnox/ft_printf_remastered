#include "ft_printf.h"

void        ft_set_moins(t_printf *handle)
{
    handle->index++;
    handle->extra->moins = ft_atoi_printf(handle);
	if (handle->str[handle->index] == '*')
	{
		handle->extra->moins = (int)va_arg(handle->ap, unsigned *);
		if (handle->extra->moins < 0)
			handle->extra->moins = -handle->extra->moins;
		handle->index++;
		return ;
	}
	if (handle->extra->moins != -4)
		handle->index += ft_nbrlen((unsigned long long)handle->extra->moins, 0);
}

void        ft_set_blanck(t_printf *handle)
{
    handle->index++;
    handle->extra->blanck = ft_atoi_printf(handle);
	if (handle->str[handle->index] == '*')
	{
		handle->extra->blanck = (int)va_arg(handle->ap, unsigned *);
		if (handle->extra->blanck < 0)
			handle->extra->blanck = -handle->extra->moins;
		handle->index++;
		return ;
	}
	if (handle->extra->blanck != -4)
 	   handle->index += ft_nbrlen((unsigned long long)handle->extra->blanck, 0);
}

void        ft_set_precision(t_printf *handle)
{
    handle->index++;
    handle->extra->precision = ft_atoi_printf(handle);
	if (handle->str[handle->index] == '*')
	{
		handle->extra->precision = (int)va_arg(handle->ap, unsigned *);
		if (handle->extra->precision < 0)
			handle->extra->precision = -handle->extra->moins;
		handle->index++;
		return ;
	}
	if (handle->extra->precision != -4)
 	   handle->index += ft_nbrlen((unsigned long long)handle->extra->precision, 0);
}

void        ft_set_zero(t_printf *handle)
{
    handle->index++;
    handle->extra->zero = ft_atoi_printf(handle);
	if (handle->str[handle->index] == '*')
	{
		handle->extra->zero = (int)va_arg(handle->ap, unsigned *);
		if (handle->extra->zero < 0)
			handle->extra->zero = -handle->extra->moins;
		handle->index++;
		return ;
	}
	if (handle->extra->zero != -4)
    	handle->index += ft_nbrlen((unsigned long long)handle->extra->zero, 0);
}

void        ft_set_width(t_printf *handle)
{
    handle->extra->width = ft_atoi_printf(handle);
    handle->index += ft_nbrlen((unsigned long long)handle->extra->width, 0);
}
