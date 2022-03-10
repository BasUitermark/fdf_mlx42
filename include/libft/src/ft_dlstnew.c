#include "../include/libft.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*head;

	head = (t_dlist *)malloc(sizeof(t_dlist));
	if (head == NULL)
		return (0);
	head->content = content;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
