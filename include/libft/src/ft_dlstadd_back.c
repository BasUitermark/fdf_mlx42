#include "../include/libft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new_item)
{
	t_dlist	*last;

	if (lst && new_item)
	{
		if (!*lst)
			*lst = new_item;
		else
		{
			last = ft_dlstlast(*lst);
			last->next = new_item;
			new_item->prev = last;
		}
	}
	return ;
}
