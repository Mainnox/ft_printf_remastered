#include "ft_printf.h"

static int		ft_reset_extra(t_printf *handle)
{
	if (handle->extra)
		free(handle->extra);
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

static t_printf		*ft_create_struct(const char *format)
{
	t_printf *handle;

	if (!(handle = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	handle->str = format;
	handle->index = 0;
	handle->nbprint = 0;
	handle->extra = NULL;
	if (!ft_reset_extra(handle))
		return (NULL);
	return (handle);
}

int			ft_printf(const char *format, ...)
{
	t_printf	*handle;

	handle = ft_create_struct(format);
	va_start(handle->ap, format);
	if (handle == NULL)
		return (-1);
	while (handle->str[handle->index])
	{
		if (handle->str[handle->index] == '%')
		{
			handle->index++;
			ft_flags_printf(handle);
			if (!ft_reset_extra(handle))
				return (-1);
		}
		ft_putchar_printf(handle);
	}
	free(handle->extra);
	free(handle);
	va_end(handle->ap);
	return (handle->nbprint);
}
