#include "../include/libft.h"

char	*ft_strnstr(const char	*big, const char *little, t_size n)
{
	t_size	i;

	i = 0;
	if (little == NULL || ft_strlen(little) == 0)
		return ((char *)big);
	if (ft_strlen(little) > n)
		return (NULL);
	while (i < n)
	{
		if (ft_strncmp((char *)&big[i], little, ft_strlen(little)) == 0)
		{
			if (i + ft_strlen(little) > n)
				return (NULL);
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
