/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:55:51 by akremer           #+#    #+#             */
/*   Updated: 2019/02/26 10:20:47 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_str(t_printf *handle, char *str)
{
	handle->nbprint += ft_strlen(str);
	write(1, str, ft_strlen(str));
}

void		ft_print_s(t_printf *handle, unsigned *s)
{
	char	*str;

	str = (char *)s;
	if (handle->extra->width && handle->extra->moins == -1 && handle->extra->zero == -1)
		ft_print_while(handle, handle->extra->width - ft_strlen(str), ' ');
	if (handle->extra->zero == 0 || handle->extra->zero == -4)
		handle->extra->zero = handle->extra->width;
	if (handle->extra->zero && handle->extra->moins == -1)
		ft_print_while(handle, handle->extra->zero - ft_strlen(str), '0');
	ft_print_str(handle, str);
	if (handle->extra->moins == 0 || handle->extra->moins == -4)
		handle->extra->moins = handle->extra->zero;
	if (handle->extra->width != -1 && handle->extra->moins != -1)
		handle->extra->moins = handle->extra->width;
	if (handle->extra->moins)
		ft_print_while(handle, handle->extra->moins - ft_strlen(str), ' ');
	handle->index++;
	handle->extra->done = 12;
}
