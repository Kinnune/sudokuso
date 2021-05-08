
#include "header.h"

int	solve(int **grid)
{
	int x = 0;
	int y = 0;
	int num = 1;
	int **grid_blank = NULL;

	grid_blank = copy_grid(grid);
	while (seek_blank(grid_blank, &y, &x, '+'))
	{
		num = grid[y][x] + 1;
		while (num <= 9)
		{
			if (check_num(grid, y, x, num))
			{
				grid[y][x] = num;
				x++;
				break ;
			}
			num++;
		}
		if (num > 9)
		{
			grid[y][x] = 0;
			if (!seek_blank(grid_blank, &y, &x, '-'))
			{
				return (0);
			}
		}
	}
	return (1);
}

int	seek_blank(int **grid, int *y, int *x, char dir)
{
	if (dir == '+')
	{
		while (*y < 9)
		{
			while (*x < 9)
			{
				if (grid[*y][*x] == 0)
				{
					return (1);
				}
				(*x)++;
			}
			(*x) = 0;
			(*y)++;
		}
	}
	else if (dir == '-')
	{
		(*x)--;
		while (*y >= 0)
		{
			while (*x >= 0)
			{
				if (grid[*y][*x] == 0)
				{
					return (1);
				}
				(*x)--;
			}
			(*x) = 8;
			(*y)--;
		}
	}
	return (0);
}
