#include "ft_printf.h"

void		ft_flags_printf(t_printf *handle)
{
	while (42)
	{
		if (handle->extra->done == -1 && handle->str[handle->index] == '-')
		{
			ft_set_moins(handle);
			continue;
		}
		if (handle->extra->done == -1 && handle->str[handle->index] == '+')
		{
			ft_set_plus(handle);
			continue;
		}
		if (handle->extra->done == -1 && handle->str[handle->index] == '#')
		{
			ft_set_hastag(handle);
			continue;
		}
		if (handle->extra->done == -1 && handle->str[handle->index] == '.')
		{
			ft_set_precision(handle);
			continue;
		}
		if (handle->extra->done == -1 && handle->str[handle->index] == ' ')
		{
			ft_set_blanck(handle);
			continue;
		}
		if (handle->extra->done == -1 && handle->str[handle->index] == '*')
		{
			ft_set_star(handle);
			continue;
		}
		if (handle->extra->done == -1 && (handle->str[handle->index] >= '1' && handle->str[handle->index] <= '9'))
		{
			ft_set_width(handle);
			continue;
		}
		if (handle->extra->done == -1 && (handle->str[handle->index] == 'j' || handle->str[handle->index] == 'h' || handle->str[handle->index] == 'l'))
		{
				ft_set_size(handle);
				continue;
		}
		if (handle->extra->done == -1 && handle->str[handle->index] == '0')
		{
			ft_set_zero(handle);
			continue;
		}
		if (handle->extra->done == -1 && (handle->str[handle->index] == 'h' || handle->str[handle->index] == 'l'))
		{
			ft_set_size(handle);
			continue;
		}
		if (handle ->extra->done == -1 && (handle->str[handle->index] == 'c' || handle->str[handle->index] == 's' || handle->str[handle->index] == 'd' || handle->str[handle->index] == 'i' || handle->str[handle->index] == 'o' || handle->str[handle->index] == 'u' || handle->str[handle->index] == 'x' || handle->str[handle->index] == 'X' || handle->str[handle->index] == '%' || handle->str[handle->index] == 'p'))
			ft_print_printf(handle);
		break;
	}
}
