/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontoya <omontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:46 by omontoya          #+#    #+#             */
/*   Updated: 2025/01/28 14:22:13 by omontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		sign;
	int		num;

	sign = 1;
	while (*str == ' ' || *str == '\t'
		|| *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 ;
		num = num + (*str - 48);
		str++;
	}
	return (sign * num);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "      ---+-+1234ab567";
// 	printf("%d\n", ft_atoi(str));
// }