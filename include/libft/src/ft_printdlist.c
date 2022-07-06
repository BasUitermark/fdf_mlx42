/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printdlist.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:48:22 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 15:11:55 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printdlist(t_dlist *list)
{
	while (list)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
}
