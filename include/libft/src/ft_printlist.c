/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printlist.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:48:29 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 15:13:31 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printlist(t_list *list)
{
	while (list)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
}
