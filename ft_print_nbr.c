/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:43:50 by akremer           #+#    #+#             */
/*   Updated: 2019/03/06 10:16:50 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_rien(void)
{
	return ;
}


static void		ft_display_signed(t_printf *handle, char *base, int ba, long long nb)
{
	if (nb < 0)
	{
		ft_print_char(handle, '-');
		nb = -nb;
	}
	if (nb >= ba)
		ft_display_signed(handle, base, ba, nb / ba);
	ft_print_char(handle, base[nb % ba]);
}

static void		ft_display_unsigned(t_printf *handle, char *base, unsigned int ba, unsigned long long nb)
{
	if (nb >= ba)
		ft_display_unsigned(handle, base, ba, nb / ba);
	ft_print_char(handle, base[nb % ba]);
}

void			ft_flags_X(t_printf *handle, char *base, unsigned int ba, unsigned long long nb)
{
	int		nbdisplay;
	int		len;

	len = ft_nbrlen(nb, 0, ba);
	if (nb == 0 && handle->extra->precision == 0)
		len = 0;
	nbdisplay = ft_cal_nbdisplay(handle, len, 'X', ba, nb);
	if (handle->extra->precision != -1)
		handle->extra->zero = -1;
	if (handle->extra->moins == -1 && handle->extra->zero == -1)
		ft_print_while(handle, handle->extra->width - nbdisplay, ' ');
	if (handle->extra->hastag == 1)
	{
		if (nb == 0)
			ft_rien();
		else
			ft_print_hastag(handle, 'X', ba);
	}
	if (handle->extra->precision != -1)
		ft_print_while(handle, handle->extra->precision - len, '0');
	if (handle->extra->zero == 1 && handle->extra->moins == -1 && handle->extra->precision == -1)
		ft_print_while(handle, handle->extra->width - nbdisplay, '0');
	if (handle->extra->precision == 0 && nb == 0)
		ft_rien();
	else
		ft_display_unsigned(handle, base, ba, nb);
	if (handle->extra->moins == 1)
		ft_print_while(handle, handle->extra->width - nbdisplay, ' ');
}

void			ft_flags_signed(t_printf *handle, char *base, unsigned int ba, long long nb)
{
	int		nbdisplay;
	char	signe;
	int		len;

	signe = (nb < 0) ? 1 : 0;
	nb = (nb < 0) ? -nb : nb;
	len = ft_nbrlen(nb, signe, ba);
	if (nb == 0 && handle->extra->precision == 0)
		len = 0;
	nbdisplay = ft_cal_nbdisplay_signed(handle, len, signe);
	if (handle->extra->precision != -1)
		handle->extra->zero = -1;
	if (handle->extra->moins == -1 && handle->extra->zero == -1)
		ft_print_while(handle, handle->extra->width - nbdisplay, ' ');
	ft_print_signe(handle, signe);
	if (handle->extra->precision != -1)
		ft_print_while(handle, handle->extra->precision - len,  '0');
	if (handle->extra->zero == 1 && handle->extra->moins == -1 && handle->extra->precision == -1)
		ft_print_while(handle, handle->extra->width - nbdisplay, '0');
	if (handle->extra->precision == 0 && nb == 0)
		ft_rien();
	else
		ft_display_signed(handle, base, ba, nb);
	if (handle->extra->moins == 1)
		ft_print_while(handle, handle->extra->width - nbdisplay, ' ');
}

void			ft_flags_unsigned(t_printf *handle, char *base, unsigned int ba, unsigned long long nb)
{
	int		nbdisplay;
	int		len;

	len = ft_nbrlen(nb, 0, ba);
	if (nb == 0 && handle->extra->precision == 0)
		len = 0;
	nbdisplay = ft_cal_nbdisplay(handle, len, 'c', ba, nb);
	if (handle->extra->precision != -1)
		handle->extra->zero = -1;
	if (handle->extra->moins == -1 && handle->extra->zero == -1)
		ft_print_while(handle, handle->extra->width - nbdisplay, ' ');
	if (handle->extra->hastag == 1)
	{
		if (nb == 0 && ba == 16)
			ft_rien();
		else
			ft_print_hastag(handle, 'c', ba);
	}
	if (handle->extra->precision != -1)
		ft_print_while(handle, handle->extra->precision - len, '0');
	if (handle->extra->zero  == 1&& handle->extra->moins == -1 && handle->extra->precision == -1)
		ft_print_while(handle, handle->extra->width - nbdisplay, '0');
	if (handle->extra->precision == 0 && nb == 0)
		ft_rien();
	else
		ft_display_unsigned(handle, base, ba, nb);
	if (handle->extra->moins == 1)
		ft_print_while(handle, handle->extra->width - nbdisplay, ' ');
}

void			ft_print_signed(t_printf *handle, int ba)
{
	char base[16] = "0123456789abcdef";

	if (handle->extra->size == 1)
		ft_flags_signed(handle, base, ba, (char)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 2)
		ft_flags_signed(handle, base, ba, (short)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 3)
		ft_flags_signed(handle, base, ba, (long)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 4)
		ft_flags_signed(handle, base, ba, (long long)va_arg(handle->ap, unsigned *));
	else 
		ft_flags_signed(handle, base, ba, (int)va_arg(handle->ap, unsigned *));
	handle->index++;
	handle->extra->done = 12;
}

void			ft_print_unsigned(t_printf *handle, unsigned int ba)
{
	char base[16] = "0123456789abcdef";

	if (handle->extra->size == 1)
		ft_flags_unsigned(handle, base, ba, (unsigned char)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 2)
		ft_flags_unsigned(handle, base, ba, (unsigned short)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 3)
		ft_flags_unsigned(handle, base, ba, (unsigned long)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 4)
		ft_flags_unsigned(handle, base, ba, (unsigned long long)va_arg(handle->ap, unsigned *));
	else 
		ft_flags_unsigned(handle, base, ba, (unsigned int)va_arg(handle->ap, unsigned *));
	handle->index++;
	handle->extra->done = 12;
}

void			ft_print_X(t_printf *handle, unsigned int ba)
{
	char base[16] = "0123456789ABCDEF";

	if (handle->extra->size == 1)
		ft_flags_X(handle, base, ba, (unsigned char)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 2)
		ft_flags_X(handle, base, ba, (unsigned short)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 3)
		ft_flags_X(handle, base, ba, (unsigned long)va_arg(handle->ap, unsigned *));
	else if (handle->extra->size == 4)
		ft_flags_X(handle, base, ba, (unsigned long long)va_arg(handle->ap, unsigned *));
	else 
		ft_flags_X(handle, base, ba, (unsigned int)va_arg(handle->ap, unsigned *));
	handle->index++;
	handle->extra->done = 12;
}
