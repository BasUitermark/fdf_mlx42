#include "../include/libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new_item)
{
	new_item->next = *lst;
	if ((*lst) != NULL)
		(*lst)->prev = new_item;
	*lst = new_item;
}
