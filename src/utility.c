
#include "header.h"

int		to_num(char ascii)
{
	return(ascii - '0');
}

int		print_ret(char *msg, int val)
{
	printf("%s", msg);
	return (val);
}

void	free_2d_int(int **ptr, int size)
{
	for (; size >= 0; size--)
	{
		free(ptr[size]);
	}
	free(ptr);
}
