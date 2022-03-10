#include "../include/libft.h"

size_t	ft_strclen(char const *str, char c)
{
	t_size	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}
