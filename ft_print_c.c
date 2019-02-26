/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:12:06 by akremer           #+#    #+#             */
/*   Updated: 2019/02/26 11:04:51 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_char(t_printf *handle, char c)
{
	handle->nbprint++;
	write(1, &c, 1);
}

void		ft_print_c(t_printf *handle, unsigned *c)
{
	if (handle->extra->width && handle->extra->moins == -1 && handle->extra->zero == -1)
		ft_print_while(handle, handle->extra->width - 1, ' ');
	if (handle->extra->zero == 0 || handle->extra->zero == -4)
		handle->extra->zero = handle->extra->width;
	if (handle->extra->zero && handle->extra->moins == -1)
		ft_print_while(handle, handle->extra->zero - 1, '0');
	ft_print_char(handle, (char)c);
	if (handle->extra->moins == 0 || handle->extra->moins == -4)
		handle->extra->moins = handle->extra->zero;
	if (handle->extra->width != -1 && handle->extra->moins != -1)
		handle->extra->moins = handle->extra->width;
	if (handle->extra->moins)
		ft_print_while(handle, handle->extra->moins - 1, ' ');
	handle->extra->done = 12;
	handle->index++;
}
