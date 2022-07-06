/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstinsert_after.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:46:32 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:46:32 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
