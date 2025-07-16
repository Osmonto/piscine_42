#include <unistd.h>

int	ft_strcmp (char *str1, char *str2);
char	**ft_sort(char **str, int nbr_params);

int	main( int argc, char **argv)
{
	char	*current_param;
	char	**str_sorted;
	int	i;
	int nbr_params;

	nbr_params = argc - 1;
	if (argc != 1)
	{	
		i = 1;
		str_sorted = ft_sort(argv,nbr_params);
		while(i <= nbr_params)
		{
			current_param = str_sorted[i];
			while(*current_param != '\0')
			{
				write (1, current_param, 1);
				current_param++;
			}
			write (1, "\n" ,1);
			i++;
		}
	}
	return (0);
}

char	**ft_sort(char **str, int nbr_params)
{
	char *tmp;
	int	i;
	int j;

	j = 1;
 	while (j <= nbr_params - 1)
	{
		i = 1;
		while (i <= nbr_params - j)
		{
			if (ft_strcmp(str[i], str[i+1])> 0)
			{
				tmp = str[i+1];
				str[i+1] = str[i];
				str[i] = tmp;
			}
			i++;
		}
		j++;
	}
	return (str);
}

int	ft_strcmp (char *str1, char *str2)
{
	int result;

	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	result = *str1 - *str2;
	return (result);
}