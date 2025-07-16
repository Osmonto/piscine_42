/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontoya <omontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:13:10 by omontoya          #+#    #+#             */
/*   Updated: 2025/01/27 15:45:21 by omontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	
	if (*to_find == '\0')
		return (str);
	
	while ( *str != '\0')
	{	
		if ( *str == *to_find)
		{
			i=0;
			while (to_find[i] != '\0' && str[i] != '\0' && str[i] == to_find[i])
			{
				i++; 
			}
			if (to_find[i] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
	

// int	main(void)
// {
// 	char	*source = "Hello world";
// 	char	*find = "wor";
// 	char	*ptr1;
// 	char	*ptr2;

// 	ptr1 = strstr(source, find);
//     if (ptr1 != NULL)
//         printf("%s\n", ptr1);
//     else
//         printf("Substring not found using strstr.\n");

//     ptr2 = ft_strstr(source, find);
//     if (ptr2 != NULL)
//         printf("%s\n", ptr2);
//     else
//         printf("Substring not found using ft_strstr.\n");
// 	return (0);
// }
