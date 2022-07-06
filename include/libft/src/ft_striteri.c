/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:49:44 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:49:44 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	t_size	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
