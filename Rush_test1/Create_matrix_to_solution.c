#include <unistd.h>


int	ft_atoi(char *str);
void	ft_putchar(char *string, int n);
void	printGrid(int grid[4][4]);

int	g_err = 1;
int g_matrix[4][4] = {{0}};
//int solve_matrix [4] [4];

void	Create_matrix_to_solve(char *str)
{
	int	a;
	int	col;
	int	row;

	a = 0;
	col = 0;
	row =0;
	while (str[a] != 0)
	{
		if (str[a] >= '0' && str[a] <= '9')
		{
			if (ft_asciitoint(&str[a]) > 0 && ft_asciitoint(&str[a]) <= 4)
			{	
				g_matrix[col][row] = ft_atoi(&str[a]);
				row++;
			}
			else
			{
				ft_putchar("number bigger than 4 entered\n", 28);
				//return (0);
			}
			if (row >= 4)
			{		
				row = 0;
				col++;
			}
			while (str[a] >= '0' && str[a] <= '9')
			{
				a++;
		    }
		}
		a++;
	}
	return;
};

int	main(int argc, char **argv)
{
	char	*str;
	//int	matrixRes[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};

	str = argv[1];
	if (argc != 2)
	{
		//g_matrix = 0;
		ft_putchar("Error  of input format\n", 26);
		return (1);
	}

	Create_matrix_to_solve(str);
	printGrid(g_matrix);
	if (g_err == 0)
		return (1);
	return (0);
}

int	ft_asciitoint(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		++str;
	}
	if (sign == -1)
		return (0);
	num = 0;
	while (*str <= '9' && *str >= '0')
	{
		if (num < 2147483647)
			num += *str - 48;
		else
			return (0);
		if (*(str + 1) <= '9' && *(str + 1) >= '0')
			num *= 10;
		str++;
	}
	return (num * sign);
}

void	ft_putchar(char *string, int n)
{
	write(1, string, n);
}

void	printGrid(int grid[4][4])
{
	int	row;
	int	col;
	int	tmp;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			tmp = grid[row][col] + 48;
			write(1, &tmp, 1);
			if (col != 3)
				write(1, " ", 1);
			col++;
		}
		ft_putchar("\n", 1);
		row++;
}
}