#include "../include/libft.h"

static int	ft_front(char const *s1, char const *set)
{
	t_size	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

static int	ft_back(char const *s1, char const *set)
{
	t_size	len;

	len = ft_strlen(s1);
	while (len > 0)
	{
		if (!ft_strchr(set, s1[len - 1]))
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	t_size	front;
	t_size	back;

	front = ft_front(s1, set);
	back = ft_back(s1, set);
	if (front >= back)
		return (ft_strdup(""));
	return (ft_substr(s1, front, back - front));
}
