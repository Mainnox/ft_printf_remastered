#include "ft_printf.h"
#include <stdio.h>

int			main()
{
	int i;
	int j;

	i =    printf("Le vrai : %f.\n", 1.001);
	j = ft_printf("Le faux : %f.\n", 1.001);
	printf("Le vrai : %d\nLe faux : %d\n", i, j);
	return (0);
}
