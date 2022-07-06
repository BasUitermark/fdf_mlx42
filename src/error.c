/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 10:18:25 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/06 10:49:53 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *error_msg, t_instance fdf)
{
	if (fdf.map.points)
		free (fdf.map.points);
	if (errno)
		perror("ERROR");
	else
		ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
