#include "../include/libft.h"

int	ft_dlstsize(t_dlist *lst)
{
	t_size	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
