/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:56:55 by akremer           #+#    #+#             */
/*   Updated: 2019/02/27 16:53:25 by akremer          ###   ########.fr       */
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
	else if (handle->extra->hastag == 1)
		len++;
	return (len);
}

int			ft_cal_nbdisplay_signed(t_printf *handle, int len, char signe)
{
	if (handle->extra->precision > len)
		len = handle->extra->precision;
	if (signe == 0 && (handle->extra->blanck == 1 || handle->extra->plus == 1))
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

void		ft_print_signe(t_printf *handle, char signe)
{
	if (signe == 1)
		ft_print_char(handle, '-');
	else if (handle->extra->plus == 1)
		ft_print_char(handle, '+');
	else if (handle->extra->blanck == 1)
		ft_print_char(handle, ' ');
}
