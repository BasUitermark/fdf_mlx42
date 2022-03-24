#include "../include/libft.h"

int	ft_max(int *array, int size)
{
	int	i;
	int	max;

	i = 0;
	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}
