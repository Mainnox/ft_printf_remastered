#include "ft_printf.h"

void        ft_set_hastag(t_printf *handle)
{
    handle->index++;
    handle->extra->hastag = 1;
}

void        ft_set_plus(t_printf *handle)
{
    handle->index++;
    handle->extra->plus = 1;
}

void        ft_set_star(t_printf *handle, va_list ap)
{
    handle->index++;
    handle->extra->width = va_arg(ap, int);
}