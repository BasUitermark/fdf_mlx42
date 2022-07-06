/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:49:46 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 15:14:41 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncat(char *dest, const char *src, unsigned int n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] && i < n)
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (dest);
}
