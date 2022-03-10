#include "../include/libft.h"

void	ft_dlstinsert_after(t_dlist *prev_node, t_dlist *new_item)
{
	if (prev_node == NULL)
		return ;
	new_item->next = prev_node->next;
	prev_node->next = new_item;
	new_item->prev = prev_node;
	if (new_item->next != NULL)
		new_item->next->prev = new_item;
}
