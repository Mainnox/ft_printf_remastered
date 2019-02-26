/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:43:50 by akremer           #+#    #+#             */
/*   Updated: 2019/02/26 15:31:43 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_display_nbr(t_printf *handle, char *base, int ba, long long nb)
{
	if (nb < 0)
	{
		ft_print_char(handle, '-');
		nb = -nb;
	}
	if (nb >= ba)
		ft_display_nbr(handle, base, ba, nb / ba);
	ft_print_char(handle, base[nb % ba]);
}

void			ft_print_nbr(t_printf *handle, int ba)
{
	char base[16] = "0123456789abcdef";

	if (handle->extra->size == 1)
		ft_display_nbr(handle, base, ba, (char)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 2)
		ft_display_nbr(handle, base, ba, (short)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 3)
		ft_display_nbr(handle, base, ba, (long)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 4)
		ft_display_nbr(handle, base, ba, (long long)va_arg(handle->ap, unsigned *));
	else 
		ft_display_nbr(handle, base, ba, (int)va_arg(handle->ap, unsigned *));
	handle->index++;
	handle->extra->done = 12;
}
