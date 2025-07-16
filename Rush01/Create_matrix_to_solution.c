#include <unistd.h>


int	ft_atoi(char *str);
void	ft_putchar(char *string, int n);
void	printGrid(int grid[4][4]);
void	Create_matrix_to_solve(char *str);
int	Condition( int row,int col,int num);
int	Condicionais(int matrix[4][4], int row, int col, int num);
int	UsedInCol(int  matrix[4][4], int col, int num);
int	UsedInRow(int grid[4][4], int row, int num);
int FindUnassignedLocation(int matrix[4][4], int *row, int *col);
int rush01(int resMatris[4][4]);
extern int g_matrix[4][4];
int	g_err = 1;
int g_matrix[4][4] = {{0}};

int	main(int argc, char **argv)
{
	char	*str;
	int	matrixRes[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};

	str = argv[1];
	if (argc != 2)
	{
		g_err = 0;
		ft_putchar("Error no formato do input\n", 26);
		return (1);
	}
	Create_matrix_to_solve(str);
	if (g_err == 0)
		return (1);
	if (rush01(matrixRes) == 1)
		printGrid(matrixRes);	
	else
	{
		ft_putchar("error\n", 6);
	}
	return (0);
}

int FindUnassignedLocation(int matrix[4][4], int *row, int *col)
{
	*row = 0;
	while (*row < 4)
  {
		*col = 0;
		while (*col < 4)
    {
			if (matrix[*row][*col] == 0)
      {
			  return (1);	
			}
			*col= *col + 1;
		}
		 *row= *row + 1;
	}
	return (0);
}

int rush01(int resMatris[4][4])
{
	int row;
	int col;
	int num;
	// verifica se tem local vazio 
	// se tiver ele  retornar 0 ele sera
	if(FindUnassignedLocation(resMatris,&row , &col) == 0)
		return (1); // Achou uma resposta
	//printGrid(resMatris);	
	//Considera os numeros 1 a 4
	num = 1;
	while(num <= 4)
	{
		// Checa se as condisoes serao verdadeiras [0][1]
																										
		if(Condicionais(resMatris,row,col,num) == 1)
		{
			// coloca o numero na posicao 
			resMatris[row][col] = num;
			// re-chama a funcao se 
			// o mapa que foi todo assinalado passar 
			// entao achamos um mapa que deu bom 
			// entao retornamos 1 indicando que deu bom 
			if(rush01(resMatris) == 1)
			{
				return(1);
			}
			// se nao nos tiramos todos os numeros que tinhas
			// postos e recomecamos 
			resMatris[row][col] = 0;
		}
		num++;
	}
	return 0;	
}

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
			if (ft_atoi(&str[a]) > 0 && ft_atoi(&str[a]) <= 4)
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

// int	main(int argc, char **argv)
// {
// 	char	*str;
// 	//int	matrixRes[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};

// 	str = argv[1];
// 	if (argc != 2)
// 	{
// 		//g_matrix = 0;
// 		ft_putchar("Error  of input format\n", 26);
// 		return (1);
// 	}

// 	Create_matrix_to_solve(str);
// 	printGrid(g_matrix);
// 	if (g_err == 0)
// 		return (1);
// 	return (0);
// }

int	ft_atoi(char *str)
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

int Condicionais(int matrix[4][4], int row, int col, int num)
{
		if (UsedInRow(matrix, row, num) == 0
			&& UsedInCol(matrix, col, num) == 0
			&& Condition(row , col , num) == 0
			&& matrix[row][col] == 0)
			return(1);	
		return(0);
}

int UsedInCol(int  matrix[4][4], int col, int num)
{
	for (int row = 0; row < 4; row++)
		if (matrix[row][col] == num)
			return (1);
  return (0);
}

int UsedInRow(int matrix[4][4], int row, int num)
{
		for (int col = 0; col < 4; col++)
			if (matrix[row][col] == num)
				return (1);
    return (0);
}

int Condition(int row, int col,int num)
{
	int row_alto = row / 2;
	int row_lado = (col / 2) + 2;
	if (row == 0 || row == 3)
	{
		if (g_matrix[row_alto][col] == 4 && num != 1)
			return (1);
		if (g_matrix[row_alto][col] == 1 && num != 4)
			return (1);
		if (g_matrix[row_alto][col] == 3 && num != 1 && num != 2)
			return (1);
	}if (col == 0 || col == 3)
	{
		if (g_matrix[row_lado][row] == 4 && num != 1)	
			return (1);
		if (g_matrix[row_lado][row] == 1 && num != 4)
			return (1);
		if (g_matrix[row_lado][row] == 3 && num != 1 && num != 2)
			return (1);
	}
	if ((row == 0 && col == 0 ) 
	|| (row == 0 && col == 3 )
	|| (row == 3 && col == 0 )
	|| (row == 3 && col == 3 ))
	{
	  if (((g_matrix[row_alto][col] == 3) || (g_matrix[row_lado][row] == 3)) && num != 2 && num != 1)
			return (1);
		if ((g_matrix[row_alto][col] == 2 || g_matrix[row_lado][row] == 2) && num != 1 && num != 2 && num != 3 )
			return (1);
		if(((g_matrix[0][col] == 3) || (g_matrix[2][row] == 3)) && ((g_matrix[1][col] == 3) || (g_matrix[3][row] == 3) )&& num != 2)
			return(1);
	}
	if  (row != 0 && col != 0 &&
	row != 3 && col != 3)
	{			
		if ((g_matrix[row_alto][col] == 4 || g_matrix[row_lado][row] == 4)  && num != 2)
				return (1);
	}
  return (0);
}
 