/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:49:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 15:14:02 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_putstr_fd(char *str, int fd)
{
	t_size	out;

	out = 0;
	if (!str)
	{
		out = write (fd, "(null)", 6);
		return (out);
	}
	out = write(fd, str, ft_strlen(str));
	return (out);
}
