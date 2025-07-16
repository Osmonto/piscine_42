/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontoya <omontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:57:48 by omontoya          #+#    #+#             */
/*   Updated: 2025/02/04 16:09:38 by omontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i] != '\0')
		i++;
	j = 0;
	while (str2[j] != '\0')
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[i + j] = '\0';
	return (str1);
}

int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "world";

	printf("%s\n", ft_strcat(str1, str2));
	return (0);
}
