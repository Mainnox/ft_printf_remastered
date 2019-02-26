#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
	ft_printf("\nLe vrai:\n");
       printf("Coucou%hhoCoucou\n", 900);
	ft_printf("\nLe faux:\n");
    ft_printf("Coucou%hhoCoucou\n", 900);
    return (0);
}
