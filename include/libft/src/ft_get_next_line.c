/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:46:46 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:46:46 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

static char	*ft_get_line(char *readstr)
{
	size_t	i;

	i = 0;
	while (readstr[i] != '\n' && readstr[i])
		i++;
	return (ft_substr(readstr, 0, i + 1));
}

static char	*ft_process(t_data_store *store)
{
	char	*line;

	line = ft_get_line(store->readstr);
	if (ft_strlen(ft_strchr(store->readstr, '\n')) != 0)
	{
		store->r_main = ft_strdup(ft_strchr(store->readstr, '\n'));
		if (!store->r_main)
			return (NULL);
	}
	free(store->readstr);
	store->readstr = NULL;
	return (line);
}

static char	*ft_read_data(int fd, t_data_store *store)
{
	static char	buff[BUFFER_SIZE + 1];
	int			b_read;

	b_read = 0;
	while (true)
	{
		if (ft_strchr(store->readstr, '\n'))
			break ;
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read < 0 && store->readstr)
		{
			free (store->readstr);
			store->readstr = NULL;
		}
		if (b_read <= 0)
			break ;
		buff[b_read] = '\0';
		store->readstr = ft_strappend(store->readstr, buff);
	}
	if (store->readstr)
		return (ft_process(store));
	return (NULL);
}

char	*ft_get_next_line(int fd)
{
	static t_data_store	store;

	if (read(fd, NULL, 0) != -1 && BUFFER_SIZE > 0)
	{
		if (store.r_main)
		{
			store.readstr = ft_strdup(store.r_main);
			free(store.r_main);
			store.r_main = NULL;
		}
		return (ft_read_data(fd, &store));
	}
	return (NULL);
}
