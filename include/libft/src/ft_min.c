#include "../include/libft.h"

int	ft_min(int *array, int size)
{
	int	i;
	int	min;

	i = 0;
	min = array[0];
	while (i < size)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}
