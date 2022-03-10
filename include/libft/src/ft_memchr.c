#include "../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	t_size	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
