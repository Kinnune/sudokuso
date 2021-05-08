
#include "header.h"

int		validate_input(char *file)
{
	int	len = 1;
	while (len < 90)
	{
		if (len % 10 == 0)
		{
			if (*file != '\n')
			{
				return (0);
			}
		}
		else if (*file > '9' || *file < '0')
		{
			return (0);
		}
		file++;
		len++;
	}
	return (1);
}

int		check_box(int **grid, int y, int x, int num)
{
	int y_start = 0;
	int x_start = 0;
	int y_i = 0;
	int x_i = 0;

	y_start = y - (y % 3);
	x_start = x - (x % 3);
	while (y_i < 3)
	{
		x_i = 0;
		while (x_i < 3)
		{
			if (grid[y_start + y_i][x_start + x_i] == num)
			{
				return (0);
			}
			x_i++;
		}
		y_i++;
	}
	return (1);
}

int		check_col_row(int **grid, int y, int x, int num)
{
	int x_check = 0;
	int y_check = 0;

	while (y_check < 9)
	{
		if (grid[y_check][x] == num)
		{
			return (0);
		}
		y_check++;
	}
	while (x_check < 9)
	{
		if (grid[y][x_check] == num)
		{
			return (0);
		}
		x_check++;
	}
	return (1);
}

int		check_num(int **grid, int y, int x, int num)
{
	if (check_box(grid, y, x, num) && check_col_row(grid, y, x, num))
	{
		return (1);
	}
	return (0);
}
