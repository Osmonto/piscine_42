/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontoya <omontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:41:00 by omontoya          #+#    #+#             */
/*   Updated: 2025/02/04 16:38:15 by omontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcat(char *str1, char *str2);
int		ft_total_length_to_allocate(char **strs, char *sep, int size);

char	*ft_strjoin(int size,char ** strs, char *sep)
{
	char 	*str_chained;
	int		total_length;
	int		i;

	if (size == 0)
	{
		if ((str_chained = malloc(sizeof(char))) == NULL)
			return (NULL);
		str_chained[0] = '\0';
	}
	else
	{
		total_length = ft_total_length_to_allocate (strs, sep, size);
		if ((str_chained = malloc((total_length + 1)*sizeof(char))) == NULL)
			return (NULL);
		i = 0;
		str_chained[0] = '\0';
		while  (i< size)
		{
			ft_strcat (str_chained, strs[i++]);
			if (i < size)
				ft_strcat (str_chained, sep);
		}
	}
	return (str_chained);
}

int	main(void)
{
	char	*strs[3];
	char	sep[] = "-";
	int		size;
	char	*result;

	strs[0] = "Hello";
	strs[1] = "World";
	strs[2] = "";
	size = 3;
	result = ft_strjoin(size, strs, sep);
	printf("%p\n", result);
	printf("%s\n", result);
	free(result);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_total_length_to_allocate(char **strs, char *sep, int size)
{
	int		total_length;
	int		i;
	char	*tmp;

	total_length = 0;
	i = 0;
	while (i < size)
	{
		tmp = strs[i];
		total_length = total_length + ft_strlen(tmp);
		if (i < size - 1)
			 total_length =total_length + ft_strlen(sep);
		i++;
	}
	return (total_length);
}

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
