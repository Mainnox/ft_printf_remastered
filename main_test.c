#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
	ft_printf("\nLe vrai:\n");
       printf("Coucou%-*cCoucou\n", -10, '1');
	ft_printf("\nLe faux:\n");
    ft_printf("Coucou%-*cCoucou\n", -10, '1');
    return (0);
}
