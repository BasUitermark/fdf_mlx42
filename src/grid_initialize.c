#include "../include/fdf.h"

static int	difference(int *array, int size)
{
	return (ft_max(array, size) - ft_min(array, size));
}

static double	set_height_mod(t_instance *fdf)
{
	double	diff;
	double	height_mod;

	height_mod = 1.0;
	diff = (double)difference(fdf->map.map_points, \
	fdf->map.map_height * fdf->map.map_width);
	while (diff > 10)
	{
		diff *= 0.5;
		height_mod *= 0.65;
	}
	return (height_mod);
}

static void	set_grid_param(t_instance *fdf)
{
	fdf->grid.size = 26;
	fdf->grid.x_offset = 0;
	fdf->grid.y_offset = 0;
	fdf->grid.height_mod = set_height_mod(fdf);
	fdf->grid.z_offset = 10 * fdf->grid.height_mod;
	fdf->grid.x_rot = 0;
	fdf->grid.y_rot = 0;
	fdf->grid.z_rot = 0;
}

static double	calc_diag(t_instance *fdf)
{
	return (sqrt(pow(fdf->map.map_width, 2) + \
	pow(fdf->map.map_height, 2)) * fdf->grid.size);
}

static void	check_grid(t_instance *fdf)
{
	while (calc_diag(fdf) + sin(0.5) * (HEIGHT / 2) > HEIGHT)
		fdf->grid.size -= 1;
	while (calc_diag(fdf) - fdf->grid.y_offset + (HEIGHT / 2) > HEIGHT)
		fdf->grid.y_offset += 20;
}

void	initialize_grid(t_instance *fdf)
{
	set_grid_param(fdf);
	check_grid(fdf);
}
