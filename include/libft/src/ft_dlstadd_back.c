/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_back.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:46:19 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:46:19 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
