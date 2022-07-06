/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:47:44 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:47:45 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	head = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node)
		{
			ft_lstadd_back(&head, node);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
	}
	return (head);
}
