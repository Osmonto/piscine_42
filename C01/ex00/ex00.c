#include <stdio.h>

void ft_ft(int *nbr);

int main(void)
{
	int a;
	int *ptr;

	a = 0;
	printf ("a initial value: %d\n",a);
	ptr = &a;
	ft_ft(ptr);
	printf("a: %d, *ptr: %d, a_address: %p\n", a, *ptr, ptr);
    return (0);
}
