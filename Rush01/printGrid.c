#include <unistd.h>

void	ft_putchar(char *string, int n);

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