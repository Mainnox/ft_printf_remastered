/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:53:08 by akremer           #+#    #+#             */
/*   Updated: 2019/03/06 09:15:48 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pc(t_printf *handle)
{
	if (handle->extra->moins == -1 && handle->extra->zero == -1)
		ft_print_while(handle, handle->extra->width - 1, ' ');
	if (handle->extra->zero == 1&& handle->extra->moins == -1)
		ft_print_while(handle, handle->extra->width - 1, '0');
	ft_print_char(handle, '%');
	if (handle->extra->moins == 1)
		ft_print_while(handle, handle->extra->width - 1, ' ');
	handle->extra->done = 12;
	handle->index++;
}
