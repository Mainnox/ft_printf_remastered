/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:54:05 by akremer           #+#    #+#             */
/*   Updated: 2019/02/27 17:37:59 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
	int i;
	int j;

    i =    printf("\nLe vrai : %0d\n", 42);
    j = ft_printf("\nLe faux : %0d\n", 42);
	printf("\nLe vrai : %d\nLe faux : %d\n", i, j);
    return (0);
}
