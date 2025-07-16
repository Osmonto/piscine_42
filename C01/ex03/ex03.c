#include <stdio.h>

void    ft_div_mod(int a, int b, int *div, int *mod);

int     main(void)
{
    int a;
    int b;
    int division;
    int modulo;
    int *div;
    int *mod;

 
    a = 25;
    b = 10;
    div = &division;
    mod = &modulo;
    if (b == 0)
    {
        printf("Error: Division by zero\n");
        return (1);
    }
    ft_div_mod(a, b, div, mod);
    printf("The result of the division is: %d\n", *div);
    printf("The result of the modulo is: %d\n", *mod);

    return (0);
}
