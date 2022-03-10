#include "../include/libft.h"

int	ft_intlen_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_out(unsigned int n)
{
	int		i;
	char	*str;

	i = ft_intlen_u(n);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i)
	{
		i--;
		str[i] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_out(n));
}
