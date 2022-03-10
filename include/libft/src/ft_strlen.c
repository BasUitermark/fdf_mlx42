#include "../include/libft.h"

size_t	ft_strlen(const char *str)
{
	t_size	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
