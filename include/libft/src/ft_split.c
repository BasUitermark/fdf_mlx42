/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:49:16 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:49:17 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static t_size	ft_wcount(char const *s, char c)
{
	t_size	i;
	t_size	wcount;

	wcount = 0;
	i = 0;
	while (!s[i])
	{
		if (s[i] != c)
			wcount++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (wcount);
}

static void	ft_clean(char **out)
{
	t_size	i;

	i = 0;
	while (out[i] != NULL)
	{
		free(out[i]);
		i++;
	}
	free (out);
	return ;
}

static char	**ft_array(t_size wcount, char const *s, char c, char **out)
{
	t_size	lcount;
	t_size	i;
	t_size	j;

	i = 0;
	j = 0;
	while (i < wcount)
	{
		while (s[j] == c)
			j++;
		lcount = ft_strclen(&s[j], c);
		out[i] = (char *)ft_calloc(lcount + 1, sizeof(char));
		if (!out[i])
		{
			ft_clean(out);
			return (NULL);
		}
		ft_strlcpy(out[i], &s[j], lcount + 1);
		j += lcount + 1;
		i++;
	}
	return (out);
}

char	**ft_split(char const *s, char c)
{
	t_size	wcount;
	char	**out;

	wcount = ft_wcount(s, c);
	out = (char **)ft_calloc(wcount + 1, sizeof(char *));
	if (!out)
		return (NULL);
	out = ft_array(wcount, s, c, out);
	return (out);
}
