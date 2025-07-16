#include <unistd.h>

void    ft_putstr(char *str)
{
	while(*str != 0)
	{
		write(1, str, 1);
		str++;
	}
}


// int main(void)
// {
// 	char str[] = "Hello World";
// 	ft_putstr(str);
// 	write (1, "\n",1);
// 	return (0);
// }