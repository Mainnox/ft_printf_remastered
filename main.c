/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:27:33 by akremer           #+#    #+#             */
/*   Updated: 2019/03/23 12:09:54 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main()
{
	int i;
	int j;

	i =    printf("Le vrai: %.f\n", -1.999);
	j = ft_printf("Le faux: %.f\n", -1.999);
	ft_printf("return du vrai: %d\nreturn du faux: %d\n", i, j);
}
