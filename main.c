#include "ft_printf.h"
#include <stdio.h>

int			main()
{
	int i;
	int j;

	i =    printf("Le vrai : %Lf\n", 10.520000);
	j = ft_printf("Le faux : %Lf\n", 10.520000);
	printf("Le vrai : %d\nLe faux : %d\n", i, j);
	return (0);
}