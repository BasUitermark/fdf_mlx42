#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_item)
{
	new_item->next = *lst;
	*lst = new_item;
}
