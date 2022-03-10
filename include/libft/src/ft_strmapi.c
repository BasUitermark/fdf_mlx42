#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	t_size	i;
	char	*out;

	i = 0;
	out = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!out || !f)
		return (NULL);
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
