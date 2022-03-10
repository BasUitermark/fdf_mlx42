#include "../include/libft.h"

void	ft_printcarray(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}