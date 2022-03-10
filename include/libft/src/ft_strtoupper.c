#include "../include/libft.h"

void	ft_strtoupper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]))
			ft_toupper(str[i]);
		i++;
	}
}
