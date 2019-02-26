/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:02:24 by akremer           #+#    #+#             */
/*   Updated: 2019/02/26 10:06:27 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_printf(t_printf *handle)
{
	if (handle->str[handle->index] == 'c' && handle->extra->done == -1)
		ft_print_c(handle, va_arg(handle->ap, unsigned*));
	if (handle->str[handle->index] == 's' && handle->extra->done == -1)
		ft_print_s(handle, va_arg(handle->ap, unsigned*));
}
