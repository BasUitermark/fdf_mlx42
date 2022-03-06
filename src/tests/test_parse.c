#include "fdf.h"

void	print_struct(t_map map)
{
	int	i = 0;
	int	j = 0;

	printf("Width: %d\nDepth: %d\n", map.map_width, map.map_depth);
	while (i < (map.map_depth * map.map_width))
	{
		while (j < map.map_width)
		{
			printf("%d ", map.map_points[i]);
			j++;
			i++;
		}
		printf("\n");
		j = 0;
	}
}

int	main(void)
{
	t_map	map;

	map = parse_map("../maps/42.fdf");
	print_struct(map);
}
