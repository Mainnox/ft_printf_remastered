/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:54:05 by akremer           #+#    #+#             */
/*   Updated: 2019/03/06 12:57:02 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
	int i;
	int j;

    i =    printf("Le vrai : %.8p\n", i);
    j = ft_printf("Le faux : %.8p\n", i);
	printf("\nLe vrai : %d\nLe faux : %d\n", i, j);
    return (0);
}
