/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:24:22 by akremer           #+#    #+#             */
/*   Updated: 2019/03/08 09:52:40 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi_printf(t_printf *handle)
{
	int			i;
	int			result;
	const char	*str;
	int			tours;

	tours = 0;
	str = handle->str;
	result = 0;
	i = handle->index;
	if (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - 48;
			tours++;
			i++;
		}
	}
	if (tours)
		return (result);
	return (-4);
}
