/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:02:24 by akremer           #+#    #+#             */
/*   Updated: 2019/03/06 13:05:40 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_printf(t_printf *handle)
{
	if (handle->str[handle->index] == 'c' && handle->extra->done == -1)
		ft_print_c(handle, va_arg(handle->ap, unsigned*));
	if (handle->str[handle->index] == 's' && handle->extra->done == -1)
		ft_print_s(handle, va_arg(handle->ap, unsigned*));
	if ((handle->str[handle->index] == 'd' || handle->str[handle->index] == 'i') && handle->extra->done == -1)
		ft_print_signed(handle, 10);
	if (handle->str[handle->index] == 'o' && handle->extra->done == -1)
		ft_print_unsigned(handle, 8);
	if (handle->str[handle->index] == 'u' && handle->extra->done == -1)
		ft_print_unsigned(handle, 10);
	if (handle->str[handle->index] == 'x' && handle->extra->done == -1)
		ft_print_unsigned(handle, 16);
	if (handle->str[handle->index] == 'X' && handle->extra->done == -1)
		ft_print_X(handle, 16);
	if (handle->str[handle->index] == '%' && handle->extra->done == -1)
		ft_print_pc(handle);
	if (handle->str[handle->index] == 'p' && handle->extra->done == -1)
	{
		handle->extra->hastag = 1;
		handle->extra->size = 6;
		ft_print_unsigned(handle, 16);
	}
	if (handle->str[handle->index] == 'U' && handle->extra->done == -1)
	{
		handle->extra->size = 3;
		ft_print_unsigned(handle, 10);
	}
}
