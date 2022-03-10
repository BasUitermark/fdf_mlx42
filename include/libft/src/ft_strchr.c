#include "../include/libft.h"

char	*ft_strchr(const char *str, int c)
{
	t_size	i;
	t_size	len;

	i = 0;
	if (!str || !c)
		return (NULL);
	len = ft_strlen(str);
	if (c == '\0')
		return (&((char *)str)[len]);
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (&((char *)str)[i + 1]);
		i++;
	}
	return (NULL);
}
