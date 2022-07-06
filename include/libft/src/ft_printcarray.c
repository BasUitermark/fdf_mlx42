/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printcarray.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:48:20 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 15:11:52 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printcarray(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}
