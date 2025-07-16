#include <unistd.h>

void	ft_putchar(char *string, int n)
{
	write(1, string, n);
}
