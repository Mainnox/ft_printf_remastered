/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 10:49:50 by akremer           #+#    #+#             */
/*   Updated: 2019/03/23 12:57:29 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_power_printf(int nb)
{
	int ret;
	int tours;

	tours = 0;
	ret = 0;
	while (nb > tours)
	{
		ret = ret * 10;
		if (tours == 0)
			ret = 10;
		tours++;
	}
	return (ret);
}

static void	ft_display_f(t_printf *h, long double deci)
{
	unsigned long long	before;
	unsigned long long	after;
	int					size_nb;

	before = (unsigned long long)deci;
	deci -= before;
	deci = (deci * ft_power_printf(h->extra->precision)) + 0.5;
	after = (unsigned long long)deci;
	size_nb = ft_nbrlen(after, 0, 10);
	if (size_nb > h->extra->precision && h->extra->precision != 0)
	{
		before++;
		size_nb = 1;
		after = 0;
	}
	ft_display_unsigned(h, "0123456789", 10, before);
	if (h->extra->precision > 0 || h->extra->hastag == 1)
		ft_print_char(h, '.');
	if (h->extra->precision > 0)
	{
		ft_print_while(h, h->extra->precision - size_nb, '0');
		ft_display_unsigned(h, "0123456789", 10, after);
	}
}

static int	ft_cal_nbdisplay_float(t_printf *h, int len, char signe)
{
	int ret;

	ret = len;
	if (h->extra->precision != 0 || h->extra->hastag == 1)
		ret++;
	ret += h->extra->precision;
	if (h->extra->blanck == 1 || h->extra->plus == 1 || signe == 1)
		ret++;
	return (ret);
}

static void	ft_print_f(t_printf *h, long double deci)
{
	int		nbdisplay;
	char	signe;
	int		len;

	signe = (deci < 0) ? 1 : 0;
	deci = (deci < 0) ? -deci : deci;
	len = ft_nbrlen((unsigned long long)deci, signe, 10);
	if (h->extra->precision == -1)
		h->extra->precision = 6;
	nbdisplay = ft_cal_nbdisplay_float(h, len, signe);
	if (h->extra->moins == -1 && h->extra->zero == -1)
		ft_print_while(h, h->extra->width - nbdisplay, ' ');
	ft_print_signe(h, signe);
	if (h->extra->zero == 1 && h->extra->moins == -1)
		ft_print_while(h, h->extra->width - nbdisplay, '0');
	if (h->extra->precision == 0 && deci == 0)
		ft_print_char(h, '0');
	else
		ft_display_f(h, deci);
	if (h->extra->moins == 1)
		ft_print_while(h, h->extra->width - nbdisplay, ' ');
}

void		ft_print_float(t_printf *h)
{
	long double deci;

	if (h->extra->size == -10)
		deci = va_arg(h->ap, long double);
	else
		deci = va_arg(h->ap, double);
	ft_print_f(h, deci);
	h->extra->done = 12;
	h->i++;
}
