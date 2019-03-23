/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:27:33 by akremer           #+#    #+#             */
/*   Updated: 2019/03/23 13:00:22 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main()
{
	int i;
	int j;
	long double Lf;
	double		f;

	ld = 1.10;
	i =    printf("Le vrai: %Lf\n", ld);
	j = ft_printf("Le faux: %Lf\n", ld);
	ft_printf("return du vrai: %d\nreturn du faux: %d\n", i, j);
}
