#include "../include/libft.h"

void	ft_strtolower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			ft_tolower(str[i]);
		i++;
	}
}
