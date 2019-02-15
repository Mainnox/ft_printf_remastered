#include "ft_printf.h"

void	ft_putchar_printf(t_printf *handle)
{
	write(1, handle->str[handle->index], 1);
	handle->nbprint++;
	handle->index++;
}
