#include <unistd.h>

int	 main (int argc, char **argv)
{
	int params;
	char *str;

	params = argc - 1;
	while (params >= 1)
	{
		str = argv[params];
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
		params--;
		write(1, "\n", 1);
	}
	return (0);
}