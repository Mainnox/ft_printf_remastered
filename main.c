#include "ft_printf.h"
#include <stdio.h>

int			main()
{
	int i;
	int j;

	i =    printf("Le vrai : %s.\n", "fsa");
	j = ft_printf("Le faux : %s.\n", "fas");
	printf("Le vrai : %d\nLe faux : %d\n", i, j);
	return (0);
}
