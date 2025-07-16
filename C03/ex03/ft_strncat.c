char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char dest1[10] = "Hello ";
// 	char dest2[10] = "Hello ";
// 	char src[20] = "Du";

// 	char *t = ft_strncat(dest1, src, 5);
// 	printf("%s\n", strncat(dest2,src,5));
// 	printf("%s\n", t);
// 	return (0);
// }

