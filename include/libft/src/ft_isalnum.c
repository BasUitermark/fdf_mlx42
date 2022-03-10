#include "../include/libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_islower(c) || ft_isupper(c));
}
