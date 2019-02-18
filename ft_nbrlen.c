#include "ft_printf.h"

int         ft_nbrlen(unsigned long long nb, char signe)
{
    int ret;

    ret = 1;
    if (signe == 1)
        ret++;
    while (nb >= 10)
    {
        nb /= 10;
        ret++;
    }
    return (ret);
}