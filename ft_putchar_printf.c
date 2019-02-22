#include "ft_printf.h"

static void		ft_putchar_seul(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_printf(t_printf *handle)
{
	ft_putchar_seul(handle->str[handle->index]);
	handle->nbprint++;
	handle->index++;
}
