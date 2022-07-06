/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:47:13 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:47:14 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_baselen(size_t n, size_t base)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(size_t n, char const *base_set)
{
	char		*out;
	size_t		i;
	size_t		base;

	if (n == 0)
		return (ft_strdup("0"));
	base = ft_strlen(base_set);
	i = ft_baselen(n, base);
	out = (char *)ft_calloc(i + 1, sizeof(char));
	if (!out)
		return (NULL);
	out[i] = '\0';
	while (i)
	{
		i--;
		out[i] = base_set[n % base];
		n /= base;
	}
	return (out);
}
