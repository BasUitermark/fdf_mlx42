#include "../include/fdf.h"

static void	put_instructions(t_instance fdf)
{
	int	x;
	int	y;

	x = 10;
	y = 10;
	mlx_put_string(fdf.mlx, "Instructions:", x, y);
	mlx_put_string(fdf.mlx, "Move map:		W/A/S/D", x, y += 20);
	mlx_put_string(fdf.mlx, "Scale map:		Q/E", x, y += 20);
}

static int	get_height(t_instance fdf, int x, int y)
{
	return (fdf.map.map_points[y * fdf.map.map_width + x] * fdf.grid.z_offset);
}

static void	draw_grid(int x, int y, t_instance fdf)
{
	if (x != fdf.map.map_width - 1)
		draw_line(fdf.img, calc_coord(fdf, x, y, get_height(fdf, x, y)), \
		calc_coord(fdf, x + 1, y, get_height(fdf, x + 1, y)));
	if (y != fdf.map.map_height - 1)
		draw_line(fdf.img, calc_coord(fdf, x, y, get_height(fdf, x, y)), \
		calc_coord(fdf, x, y + 1, get_height(fdf, x, y + 1)));
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
			draw_grid(x, y, fdf);
			x++;
		}
		x = 0;
		y++;
	}
	put_instructions(fdf);
	mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
}
