#include <unistd.h>

void    ft_putchar(char a)
{
    write(1, &a, 1);
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + '0');
}

// int main(void)
// {
//     ft_putnbr(2147483647);  // Max Int Value 2147483647
//     return (0);
// }
