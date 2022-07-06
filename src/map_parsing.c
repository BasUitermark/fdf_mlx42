/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 09:26:50 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/06 17:05:07 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	count_width(char *str_map)
{
	int	width_count;
	int	i;

	width_count = 0;
	i = 0;
	while (str_map[i] != '\n')
	{
		if (ft_isdigit(str_map[i]))
		{
			width_count++;
			while (ft_isdigit(str_map[i]))
				i++;
		}
		if (str_map[i] == ' ' || str_map[i] == '-')
			i++;
		if (str_map[i] == ',')
		{
			while (!ft_isspace(str_map[i]))
				i++;
		}
	}
	return (width_count);
}

static t_map	process(char *str_map, int depth_count)
{
	t_map	map;
	int		i;
	int		num;

	i = 0;
	num = 0;
	map.height = depth_count;
	map.width = count_width(str_map);
	map.points = (int *)ft_calloc(depth_count * map.width, sizeof(int));
	while (str_map[i])
	{
		if (ft_isdigit(str_map[i]) || str_map[i] == '-')
		{
			map.points[num] = ft_atoi(&str_map[i]);
			num++;
		}
		while (!ft_isspace(str_map[i]) && str_map[i])
			i++;
		while (ft_isspace(str_map[i]) && str_map[i])
			i++;
	}
	free (str_map);
	return (map);
}

char	*read_map(int fd, int *depth_count)
{
	char	*temp;
	char	*str_map;

	str_map = NULL;
	while (true)
	{
		temp = ft_get_next_line(fd);
		if (temp)
		{
			str_map = ft_strappend(str_map, temp);
			*depth_count += 1;
		}
		else
			break ;
		free(temp);
	}
	return (str_map);
}

t_map	parse_map(const char *filepath)
{
	int		fd;
	int		depth_count;
	char	*str_map;

	depth_count = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0 || !ft_strnstr(filepath, ".fdf", ft_strlen(filepath)))
		error("Invalid pathname! Path needs to end on: \".fdf\"!");
	str_map = read_map(fd, &depth_count);
	if (!str_map)
		error("Failed to read map!");
	close(fd);
	return (process(str_map, depth_count));
}
