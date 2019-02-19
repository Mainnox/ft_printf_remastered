#include "ft_printf.h"

void        ft_set_moins(t_printf *handle)
{
    handle->index++;
    handle->extra->moins = ft_atoi_printf(handle);
    handle->index += ft_nbrlen((unsigned long long)handle->extra->moins, 0);
}

void        ft_set_blanck(t_printf *handle)
{
    handle->index++;
    handle->extra->blanck = ft_atoi_printf(handle);
    handle->index += ft_nbrlen((unsigned long long)handle->extra->blanck, 0);
}

void        ft_set_precision(t_printf *handle)
{
    handle->index++;
    handle->extra->precision = ft_atoi_printf(handle);
    handle->index += ft_nbrlen((unsigned long long)handle->extra->precision, 0);
}

void        ft_set_zero(t_printf *handle)
{
    handle->index++;
    handle->extra->zero = ft_atoi_printf(handle);
    handle->index += ft_nbrlen((unsigned long long)handle->extra->zero, 0);
}

void        ft_set_width(t_printf *handle)
{
    handle->extra->width = ft_atoi_printf(handle);
    handle->index += ft_nbrlen((unsigned long long)handle->extra->width, 0);
}
