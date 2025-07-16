int ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
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
//     char *test2 = "HELLO";    
//     char *test3 = "Hello";    
//     char *test4 = "123";      
    
//     printf("Empty string: %d\n", ft_str_is_uppercase(test1));
//     printf("Uppercase: %d\n", ft_str_is_uppercase(test2));
//     printf("Mixed case: %d\n", ft_str_is_uppercase(test3));
//     printf("Numbers: %d\n", ft_str_is_uppercase(test4));
// 	return (0);
// }
