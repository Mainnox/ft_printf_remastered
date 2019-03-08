#include "ft_printf.h"
#include <stdio.h>

int			main()
{
	int i;
	int j;

	i =    printf("Le vrai : !%45lc!\n", 9889);
	j = ft_printf("Le faux : !%45lc!\n", 9889);
	printf("Le vrai : %d\nLe faux : %d\n", i, j);
	return (0);
}
