#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;

	out = malloc(count * size);
	if (!out)
		return (NULL);
	return (ft_memset(out, 0, count * size));
}
