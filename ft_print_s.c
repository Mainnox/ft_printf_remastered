/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:55:51 by akremer           #+#    #+#             */
/*   Updated: 2019/03/06 09:01:30 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_str(t_printf *handle, char *str)
{
	handle->nbprint += ft_strlen(str);
	write(1, str, ft_strlen(str));
}

static void	ft_print_pre(t_printf *handle, char *str, int len)
{
	handle->nbprint += len;
	write(1, str, len);
}

static int	ft_cal_len(t_printf *handle, char *str)
{
	int len;

	len = ft_strlen(str);
	if (handle->extra->precision != -1 && len > handle->extra->precision)
		len = handle->extra->precision;
	return (len);
}

void		ft_print_s(t_printf *handle, unsigned *s)
{
	char	*str;
	int		len;

	str = (char *)s;
	len = ft_cal_len(handle, str);
	if (handle->extra->precision != -1)
		handle->extra->zero = -1;
	if (handle->extra->moins == -1 && handle->extra->zero == -1)
		ft_print_while(handle, handle->extra->width - len, ' ');
	if (handle->extra->zero == 1 && handle->extra->moins == -1)
		ft_print_while(handle, handle->extra->width - len, '0');
	ft_print_pre(handle, str, len);
	if (handle->extra->moins == 1)
		ft_print_while(handle, handle->extra->width - len, ' ');
	handle->index++;
	handle->extra->done = 12;
}
