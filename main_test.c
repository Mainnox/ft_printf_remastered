/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:54:05 by akremer           #+#    #+#             */
/*   Updated: 2019/02/27 15:53:44 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
	ft_printf("\nLe vrai:\n");
       printf("Coucou%09%Coucou\n");
	ft_printf("\nLe faux:\n");
    ft_printf("Coucou%09%Coucou\n");
    return (0);
}
