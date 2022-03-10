#include "../include/libft.h"

char	*ft_strdup(const char *str)
{
	char	*out;
	size_t	len;

	len = ft_strlen(str);
	if (!str)
		return (NULL);
	out = (char *)ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, str, len + 1);
	out[len] = '\0';
	return (out);
}
