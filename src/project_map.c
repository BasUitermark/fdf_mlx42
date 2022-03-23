#include "../include/fdf.h"

static t_coord	translate_coord(int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

static void	isometric(int *x, int *y)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(0.523599);
	*y = (temp_x + temp_y) * sin(0.523599);
}

static t_coord	calc_coord(int x, int y, int z)
{
	x *= GRIDSIZE;
	y *= GRIDSIZE;
	isometric(&x, &y);
	x += WIDTH / 2;
	y += -z + HEIGHT / 2;
	return (translate_coord(x, y));
}

static int	search_height(t_instance fdf, int x, int y)
{
	return (fdf.map.map_points[y * fdf.map.map_width + x] * Z_OFFSET);
}

static void	draw_grid(int x, int y, t_instance fdf)
{
	if (x != fdf.map.map_width - 1)
		draw_line(fdf.img, calc_coord(x, y, search_height(fdf, x, y)), \
		calc_coord(x + 1, y, search_height(fdf, x + 1, y)));
	if (y != fdf.map.map_height - 1)
		draw_line(fdf.img, calc_coord(x, y, search_height(fdf, x, y)), \
		calc_coord(x, y + 1, search_height(fdf, x, y + 1)));
}

void	project_map(t_instance fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	// check_map_size(fdf);
	while (y < fdf.map.map_height)
	{
		while (x < fdf.map.map_width)
		{
			draw_grid(x, y, fdf);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
}
