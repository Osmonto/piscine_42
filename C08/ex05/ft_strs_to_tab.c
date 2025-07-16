/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontoya <omontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:50:51 by azellner          #+#    #+#             */
/*   Updated: 2025/02/05 16:14:46 by omontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

void	ft_strlcpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[n] = 0;
}

char	*ft_malloc_str(char *str, int size)
{
	int	i;

	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

void	ft_free_struct(t_stock_str *stock, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		free(stock[i].copy);
		i++;
	}
	free(stock);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			i;
	int			size;

	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock)
		return (0);
	i = 0;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		stock[i].size = size;
		stock[i].str = av[i];
		stock[i].copy = ft_malloc_str(stock[i].copy, size);
		if (!stock[i].copy)
		{
			ft_free_struct(stock, ac);
			return (0);
		}
		ft_strlcpy(stock[i].copy, av[i], size);
		i++;
	}
	stock[ac].str = 0;
	return (stock);
}
int	main(void)
{
	char	*strs[3];
	int		size;
	struct s_stock_str	*result;

	strs[0] = "Hello";
	strs[1] = "World";
	strs[2] = "Perro";
	size = 3;
	result = ft_strs_to_tab(size, strs);
	ft_show_tab(result);

	printf("%s\n",(++result)->str);
	return (0);
}

