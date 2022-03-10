#include "../include/libft.h"

void	ft_printiarray(int **array, size_t lines, size_t size)
{
	size_t	line = 0;
	size_t	column = 0;

	while (line < lines)
	{
		while (column < size)
		{
			ft_printf("%d ", array[line][column]);
			column++;
		}
		ft_printf("\n");
		column = 0;
		line++;
	}
}