#include "fdf.h"

int	initialize(mlx_t mlx, int width, int height, char *title)
{
	mlx = mlx_init(WIDTH, HEIGHT, title, TRUE);
	if (!mlx)
		return (0);
	return (1);
}
