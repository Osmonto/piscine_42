#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int params;
	char *str;
	
	i = 1;
	str = *argv;
	params = argc-1;
	while (params >= 1)
	{
		str = argv [i];
		while (*str != '\0')
		{
			write (1, str, 1);
			str ++;
		}
		write (1,"\n", 1);
		params--;
		i++;
		
	}
	return (0);
}