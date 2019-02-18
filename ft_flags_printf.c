#include "ft_printf.h"

void		ft_flags_printf(t_printf *handle, va_list ap)
{
	if (handle->extra->done == -1 && handle->str[handle->index] == '-')
		ft_set_moins(handle);
	if (handle->extra->done == -1 && handle->str[handle->index] == '+')
		ft_set_plus(handle);
	if (handle->extra->done == -1 && handle->str[handle->index] == '#')
		ft_set_hastag(handle);
	if (handle->extra->done == -1 && handle->str[handle->index] == '.')
		ft_set_precision(handle);
	if (handle->extra->done == -1 && handle->str[handle->index] == ' ')
		ft_set_blanck(handle);
	if (handle->extra->done == -1 && handle->str[handle->index] == '*')
		ft_set_star(handle, ap);
	if (handle->extra->done == -1 && handle->str[handle->index] >= '1' && handle->str[handle->index] <= '9')
		ft_set_width(handle);
	if (handle->extra->done == -1 && (handle->str[handle->index] == 'h' || handle->str[handle->index] == 'l')
		ft_set_size(handle);
	if (handle->extra->done == -1 && handle->str[handle->index] == '0')
		ft_set_zero(handle);
}
