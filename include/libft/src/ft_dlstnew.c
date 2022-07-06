/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstnew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:46:37 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:46:38 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
