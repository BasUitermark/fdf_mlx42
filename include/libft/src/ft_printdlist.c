#include "../include/libft.h"

void	ft_printdlist(t_dlist *list)
{
	while (list)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
}