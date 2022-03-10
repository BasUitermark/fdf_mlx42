#include "../include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	t_size	len;

	len = ft_strlen(str) + 1;
	while (len > 0)
	{
		len--;
		if (str[len] == (unsigned char)c)
			return (&((char *)str)[len]);
	}
	return (NULL);
}
