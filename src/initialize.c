#include "fdf.h"

int	initialize(t_mlx_data *mlx, int width, int height, char *title)
{
	if (width <= 0 || height <= 0 || width > 1920 || height > 1080)
		return (0);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, width, height, title);
	if (!mlx->win)
		return (0);
	return (mlx_clear_window(mlx->mlx, mlx->win));
}
