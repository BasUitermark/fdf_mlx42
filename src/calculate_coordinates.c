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

t_coord	calc_coord(t_instance fdf, int x, int y, int z)
{
	x *= fdf.grid.size;
	y *= fdf.grid.size;
	isometric(&x, &y);
	x += WIDTH / 2 - fdf.grid.x_offset;
	y += -z + HEIGHT / 2 - fdf.grid.y_offset;
	return (translate_coord(x, y));
}