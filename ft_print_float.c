/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 10:49:50 by akremer           #+#    #+#             */
/*   Updated: 2019/03/23 12:07:07 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	if (h->extra->precision == -1)
		h->extra->precision = 6;
	deci = (deci * ft_power_printf(h->extra->precision)) + 0.5;
	after = (unsigned long long)deci;
	size_nb = ft_nbrlen(after, 0, 10);
	if (size_nb > h->extra->precision)
	{
		before++;
		size_nb = 1;
		after = 0;
	}
	ft_display_unsigned(h, "0123456789", 10, before);
	if (h->extra->precision > 0)
	{
		ft_print_char(h, '.');
		ft_print_while(h, h->extra->precision - size_nb, '0');
		ft_display_unsigned(h, "0123456789", 10, after);
	}
}

static void	ft_print_f(t_printf *h, long double deci)
{
//	ft_display_signe();
	ft_display_f(h, deci);
}

void		ft_print_float(t_printf *h)
{
	long double deci;

	if (h->extra->size == -10)
	{
		deci = va_arg(h->ap, long double);
	}
	else
		deci = va_arg(h->ap, double);
	ft_print_f(h, deci);
	h->extra->done = 12;
	h->i++;
}
