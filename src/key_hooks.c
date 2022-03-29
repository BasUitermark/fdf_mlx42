#include "../include/fdf.h"

void	key_hooks(void *param)
{
	t_instance	*fdf;

	fdf = (t_instance *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_A) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_S) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		location(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q) || mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		zoom(fdf);
}

void	close_hook(void *param)
{
	t_instance	*fdf;

	fdf = (t_instance *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fdf->mlx);
		exit(EXIT_SUCCESS);
	}
}
