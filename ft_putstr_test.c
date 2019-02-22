void    ft_putchar_test(char c)
{
    write(1, &c, 1);
}

void    ft_putstr_test(char *str)
{
    while (*str)
        ft_putchar_test(*str++);
}