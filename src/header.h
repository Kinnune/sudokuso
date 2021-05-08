#ifndef HEADER_H
#define HEADER_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//		grid_functions.c
int		**make_grid(char *file);
void	print_grid(int **grid);
int		**copy_grid(int **grid);

//		logic.c
int		solve(int **grid);
int		seek_blank(int **grid, int *y, int *x, char dir);

//		num_validation.c
int		check_box(int **grid, int y, int x, int num);
int		check_col_row(int **grid, int y, int x, int num);
int		check_num(int **grid, int y, int x, int num);
int		validate_input(char *file);

//		utility.c
int		to_num(char ascii);
int		print_ret(char *msg, int val);
void	free_2d_int(int **ptr, int size);

#endif
