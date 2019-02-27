/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:56:55 by akremer           #+#    #+#             */
/*   Updated: 2019/02/27 12:49:56 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_while(t_printf *handle, int len, char c)
{
	handle->nbprint += len;
	while (len > 0)
	{
		ft_print_char(handle, c);
		len--;
	}
}

int			ft_cal_nbdisplay(t_printf *handle, int len, char c, unsigned int ba)
{
	if (handle->extra->precision > len)
		len = handle->extra->precision;
	if (handle->extra->hastag == 1 && c == 'X')
		len += 2;
	else if (handle->extra->hastag == 1 && ba == 16)
		len += 2;
	else
		len++;
	return (len);
}

void		ft_print_hastag(t_printf *handle, char c, unsigned int ba)
{
	if (c == 'X')
		ft_print_str(handle, "0X");
	else if (ba == 16)
		ft_print_str(handle, "0x");
	else
		ft_print_char(handle, '0');
}
