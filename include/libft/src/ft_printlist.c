#include "../include/libft.h"

void	ft_printlist(t_list *list)
{
	while (list)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
}