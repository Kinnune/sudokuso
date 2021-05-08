
#include "header.h"

void	print_grid(int **grid)
{
	int x = 0;
	int y = 0;

	while (y < 9)
	{
		while (x < 9)
		{
			printf("%d", grid[y][x]);
			x++;
			if (x == 3 || x == 6)
			{
				printf(" ");
			}
		}
		y++;
		if (y == 3 || y == 6)
		{
			printf("\n");
		}
		x = 0;
		printf("\n");
	}
}

int		**make_grid(char *file)
{
	int i = 0;
	int row = -1;
	int	sudo_nums = 81;
	int **grid = NULL;

	if (!(grid = malloc((sizeof(int *) * 9))))
	{
		fprintf(stderr, "MALLOC ERROR\n");
		exit(1);
	}
	for (sudo_nums = 81; sudo_nums > 0; sudo_nums--)
	{
		if (sudo_nums % 9 == 0)
		{
			i = 0;
			row++;
			if (!(grid[row] = malloc((sizeof(int) * 9))))
			{
				fprintf(stderr, "MALLOC ERROR\n");
				free_2d_int(grid, row);
				exit(1);
			}
			if (*file == '\n')
			{
				file++;
			}
		}
		grid[row][i] = to_num(*file);
		file++;
		i++;
	}
	return (grid);
}

int		**copy_grid(int **grid)
{
	int col = 0;
	int row = 0;
	int **grid_blank = NULL;

	if (!(grid_blank = malloc((sizeof(int *) * 9))))
	{
		fprintf(stderr, "MALLOC ERROR\n");
		exit(1);
	}
	for (row = 0; row < 9; row++)
	{
		if (!(grid_blank[row] = malloc((sizeof(int) * 9))))
		{
			fprintf(stderr, "MALLOC ERROR\n");
			free_2d_int(grid, row);
			exit(1);
		}
		for (col = 0; col < 9; col++)
		{
			grid_blank[row][col] = grid[row][col];
		}
	}
	return (grid_blank);
}
