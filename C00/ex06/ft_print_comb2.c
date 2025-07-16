#include <unistd.h>

void    ft_putchar( char a, char b)
{
    write(1, &a, 1);
    write(1, &b, 1);
}

void ft_print_comb2(void)
{
    int i = 0;
    int j = 0;
    
    while (i <= 98)
    {
        j=i+1;
        while(j <= 99)
        {
        ft_putchar(i / 10+'0' ,i % 10 + '0');
        write(1, " ", 1);
        ft_putchar(j / 10+'0' ,j % 10 + '0');
        if(i!=98 || j!=99)
        {
            write(1, ", ", 2);
        }
        j++;
        }
    i++;
    }
}

int main(void)
{
    ft_print_comb2();
    return (0);
}
