#include "fdf.h"

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
		if (str_map[i] == ' ')
			i++;
		if (str_map[i] == ',')
			i += 9;
	}
	return (width_count);
}

static t_map	process(char *str_map, int depth_count)
{
	t_map	map;
	int		i;
	int		num;

	i = 0;
	num = -1;
	map.map_depth = depth_count;
	map.map_width = count_width(str_map);
	map.map_points = (int *)ft_calloc(depth_count * map.map_width, sizeof(int));
	while (str_map[i])
	{
		if (ft_isdigit(str_map[i]))
			map.map_points[++num] = ft_atoi(&str_map[i]);
		while (!ft_isspace(str_map[i]))
			i++;
		while (ft_isspace(str_map[i]))
			i++;
	}
	free (str_map);
	return (map);
}

t_map	parse_map(char *filepath)
{
	int		fd;
	int		depth_count;
	char	*temp;
	char	*str_map;

	depth_count = 0;
	str_map = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0 || !ft_strnstr(filepath, ".fdf", ft_strlen(filepath)))
		error(RED"Invalid pathname! Needs to be \".fdf\""RESET);
	while (true)
	{
		temp = ft_get_next_line(fd);
		if (temp)
		{
			str_map = ft_strappend(str_map, temp);
			depth_count++;
		}
		else
			break ;
		free(temp);
	}
	close(fd);
	return (process(str_map, depth_count));
}
