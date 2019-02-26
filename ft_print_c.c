/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:12:06 by akremer           #+#    #+#             */
/*   Updated: 2019/02/26 07:28:46 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_char(t_printf *handle, char c)
{
	handle->nbprint++;
	write(1, &c, 1);
}

void		ft_print_c(t_printf *handle, unsigned *c)
{
	ft_print_char(handle, (char)c);
	handle->index++;
	return ;
}
