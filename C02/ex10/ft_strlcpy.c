/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontoya <omontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:09 by omontoya          #+#    #+#             */
/*   Updated: 2025/01/23 16:54:37 by omontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;


	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}

	if (size == 0)
		return (src_len);
	i=0;
	while (i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
	if (size > 0)
		dest[i] = '\0';
	
	return (src_len);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char			src[] = "Hello";
	char			src2[] = "Hello";
	char			dest[3] ="bla";
	char			dest2[3]="bla";
	unsigned int	size;
 
    /* Get buffer size */
    size = 5;
    /* Test and compare results */
    printf("Source: %s\n", src);
    printf("Destination before: %s\n", dest);
    printf("Destination before original: %s\n", dest2);
	printf("Custom ft_strlcpy: %u\n", ft_strlcpy(dest, src, size));
	printf("Original strlcpy: %lu\n", strlcpy(dest2, src2, size));
    printf("Destination after: %s\n", dest);
	printf("Destination after original: %s\n", dest2);
	printf("Size of dest: %lu\n", sizeof(dest));
	printf("Size of dest: %lu\n", sizeof(dest2));
	return (0);
}
