#include "../include/libft.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n *= -1);
	return (n);
}
