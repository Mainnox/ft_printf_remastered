/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:54:05 by akremer           #+#    #+#             */
/*   Updated: 2019/02/27 12:51:41 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
	ft_printf("\nLe vrai:\n");
       printf("Coucou%#09*xCoucou\n",8 , 42);
	ft_printf("\nLe faux:\n");
    ft_printf("Coucou%#09*xCoucou\n",8 ,  42);
    return (0);
}
