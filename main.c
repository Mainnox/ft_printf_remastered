#include "ft_printf.h"
#include <stdio.h>

int			main()
{
	int i;
	int j;

	i =    printf("Le vrai : %#23.44X\n", 0);
	j = ft_printf("Le faux : %#23.44X\n", 0);
	printf("Le vrai : %d\nLe faux : %d\n", i, j);
	return (0);
}
