int ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
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
//	char *test1 = "";         
//	char *test2 = "hello";    
//	char *test3 = "Hello";    
//	char *test4 = "123";      
    
//	printf("Empty string: %d\n", ft_str_is_lowercase(test1));
//	printf("Lowercase: %d\n", ft_str_is_lowercase(test2));
//	printf("Mixed case: %d\n", ft_str_is_lowercase(test3));
//	printf("Numbers: %d\n", ft_str_is_lowercase(test4));
//	return (0);  
// }
