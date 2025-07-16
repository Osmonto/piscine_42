#include <stdio.h>

void    ft_swap(int *a, int *b);

int main(void)
{
    int *a;
    int *b;
    int x;
    int y;

    x = 10;
    y = 20;
    a = &x;
    b = &y;
    printf ("Before swap a:%d , b:%d\n",*a,*b);
    ft_swap(a, b);
    printf ("After swap a: %d , b: %d\n",*a,*b);
    return (0);
}
