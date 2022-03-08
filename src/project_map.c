#include "../include/fdf.h"

void	project_map(mlx_t *mlx, mlx_image_t *img, t_map map)
{
	t_coord	start;
	t_coord	end;

	start.x = 50;
	start.y = 50;
	end.x = 500;
	end.y = 500;
	map.map_points++;
	while (start.x < 200)
	{
		draw_line(mlx, img, start, end);
		start.x += 5;
	}
}
