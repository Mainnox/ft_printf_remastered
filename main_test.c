#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
	ft_printf("\nLe vrai:\n");
       printf("Coucou%10sCoucou\n", "Cle test");
	ft_printf("\nLe faux:\n");
    ft_printf("Coucou%10sCoucou\n", "Cle test");
	printf("%hhd", (unsigned char)1000);
    return (0);
}
