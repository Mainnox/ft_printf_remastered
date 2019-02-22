#include "ft_printf.h"

static int		ft_reset_extra(t_printf *handle)
{
	if (handle->extra)
		free(extra);
	if (!(handle->extra = (t_extra *)malloc(sizeof(t_extra))))
		return (0);
	handle->extra->plus = -1;
	handle->extra->moins = -1;
	handle->extra->hastag = -1;
	handle->extra->precision = -1;
	handle->extra->blanck = -1;
	handle->extra->done = -1;
	handle->extra->width = -1;
	handle->extra->size = -1;
	handle->extra->zero = -1;
	return (1);
}

static int		ft_create_struct(const char *format, t_printf *handle)
{
	if (!(handle = (t_printf *)malloc(sizeof(t_printf))))
		return (-1);
	handle->str = format;
	handle->index = 0;
	handle->nbprint = 0;
	handle->extra = NULL;
	if (!ft_reset_extra(handle))
		return (0);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_printf	*handle;
	va_list		ap;

	va_start(ap, format);
	if (!ft_create_struct(format, handle))
		return (-1);
	while (handle->str[handle->index])
	{
		if (handle->str[handle->index] == '%')
		{
			handle->index++;
			ft_flags_printf(handle, ap);
			if (!ft_reset_extra(handle))
				return (-1);
		}
		ft_putchar_printf(handle);
	}
	free(handle->extra);
	free(handle);
	va_end(ap);
	return (handle->nbprint);
}
