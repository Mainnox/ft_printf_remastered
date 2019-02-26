/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:56:55 by akremer           #+#    #+#             */
/*   Updated: 2019/02/26 08:34:51 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_while(t_printf *handle, int len, char c)
{
	while (len > 0)
	{
		ft_print_char(handle, c);
		len--;
	}
}
