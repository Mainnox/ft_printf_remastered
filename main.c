#include "ft_printf.h"
#include <stdio.h>

int			main()
{
	int i;
	int j;

	i =    printf("Le vrai : %#.44zo42\n", 0);
	j = ft_printf("Le faux : %#.44zo42\n", 0);
	printf("Le vrai : %d\nLe faux : %d\n", i, j);
	return (0);
}
