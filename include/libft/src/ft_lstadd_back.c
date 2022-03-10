#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_item)
{
	t_list	*last;

	if (lst && new_item)
	{
		if (!*lst)
		{
			*lst = new_item;
			return ;
		}
		else
		{
			last = ft_lstlast(*lst);
			last->next = new_item;
		}
	}
}
