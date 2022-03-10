#include "../include/libft.h"

void	ft_dlstdel_node(t_dlist **lst, t_dlist *del_node)
{
	if (*lst == NULL || del_node == NULL)
		return ;
	if (*lst == del_node)
		*lst = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (del_node ->prev != NULL)
		del_node->prev->next = del_node->next;
	free(del_node);
	return ;
}
