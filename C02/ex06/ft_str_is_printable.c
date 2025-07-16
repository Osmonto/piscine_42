int ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if ((int)*str >= 32 && (int)*str <= 126)
		{
			str++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

// #include<stdio.h>

// int	main(void)
// {
//     char *test1 = "";         
//     char *test2 = "HELLO\t";    
//     char *test3 = "H 0l?o";    
    
//     printf("Empty string: %d\n", ft_str_is_printable(test1));
//     printf("Nonprintable with Tab: %d\n", ft_str_is_printable(test2));
//     printf("Leertaste case: %d\n", ft_str_is_printable(test3));
//    	return (0);
// }