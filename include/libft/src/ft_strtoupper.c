/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:50:08 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:50:09 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_strtoupper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]))
			ft_toupper(str[i]);
		i++;
	}
}
