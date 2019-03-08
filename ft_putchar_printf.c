/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:03:31 by akremer           #+#    #+#             */
/*   Updated: 2019/03/08 11:27:39 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putchar_seul(char c)
{
	write(1, &c, 1);
}

void			ft_putchar_printf(t_printf *h)
{
	ft_putchar_seul(h->str[h->i]);
	h->nbprint++;
	h->i++;
}
