#include "../include/fdf.h"

t_coord	coord_process(int x, int y)
{
	t_coord	coord;

	coord.x += x + WIDTH / 2;
	coord.y += y + HEIGHT / 2;
	printf("x: %d\n", coord.x);
	printf("y: %d\n", coord.y);
	return (coord);
}

void	draw_grid_line(int x, int y, t_instance fdf)
{
	draw_line(fdf.mlx, fdf.img, coord_process(x, y), coord_process(x + 1, y));
	draw_line(fdf.mlx, fdf.img, coord_process(x, y), coord_process(x, y + 1));
}

void	project_map(t_instance fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_grid_line(x, y, fdf);
	// while (y < fdf.map.map_depth)
	// {
	// 	while (x < fdf.map.map_width)
	// 	{
	// 		draw_grid_line(x, y, fdf);
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }
}
