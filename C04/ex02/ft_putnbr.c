#include <unistd.h>

void    ft_putnbr(int nb)
{
    char c;
    
    if (nb == -2147483648)
    {
            write (1, "-2147483648", 11);
            return;
    }
    if (nb < 0)
    {
        write (1,"-", 1);
        nb = -nb;
    }

    if (nb > 9)
    {
     ft_putnbr(nb/10);
     ft_putnbr(nb%10);
    }
    else
    {
        c = nb +'0';
        write (1, &c, 1);
    }
}

// int main(void)
// {
//     int x;
//     x = 214748;
//     ft_putnbr(x);
//     write (1, "\n",1);
//     return (0);
// }