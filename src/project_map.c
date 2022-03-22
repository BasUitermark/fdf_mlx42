#include "../include/fdf.h"

t_coord	translate_coord(int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

void	isometric(int *x, int *y)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(0.523599);
	*y = (temp_x + temp_y) * sin(0.523599);
}

t_coord	calc_coord(int x, int y)
{
	x *= GRIDSIZE;
	y *= GRIDSIZE;
	isometric(&x, &y);
	x += WIDTH / 2;
	y += HEIGHT / 2;
	return (translate_coord(x, y));
}

void	grid_line(int x, int y, t_instance fdf)
{
	if (x != fdf.map.map_width - 1)
		draw_line(fdf.mlx, fdf.img, calc_coord(x, y), calc_coord(x + 1, y));
	if (y != fdf.map.map_height - 1)
		draw_line(fdf.mlx, fdf.img, calc_coord(x, y), calc_coord(x, y + 1));
}

void	project_map(t_instance fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf.map.map_height)
	{
		while (x < fdf.map.map_width)
		{
			grid_line(x, y, fdf);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
}
