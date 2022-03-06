#include "fdf.h"

static void	close_win(t_mlx_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

int	key_hooks(int key, t_mlx_data *mlx)
{
	if (key == ESC_KEY)
		close_win(mlx);
	return (0);
}
