/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:02:24 by akremer           #+#    #+#             */
/*   Updated: 2019/02/26 09:06:33 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_printf(t_printf *handle)
{
	if (handle->str[handle->index] == 'c')
		ft_print_c(handle, va_arg(handle->ap, unsigned*));
}