
#include "header.h"

int	main(int argc, char **argv)
{
	int		fd = 0;
	int		**grid = NULL;
	char	file_buff[128];

	if (argc != 2)
	{
		return (print_ret("Usage: ./suso /path/to/file\n", 0));
	}
	fd = open(argv[1], O_RDONLY);
	if (read(fd, file_buff, 127) < 0)
	{
		return (print_ret("Read error!\n", 0));
	}
	if (!validate_input(file_buff))
	{
		return (print_ret("Wrong format!\n", 0));
	}
	grid = make_grid(file_buff);
	if (!solve(grid))
	{
		return (print_ret("Seems impossible..\n", 0));
	}
	print_grid(grid);
	return(0);
}
