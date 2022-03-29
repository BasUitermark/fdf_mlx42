#include "../include/fdf.h"

static void	execute_move(t_instance *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	project_map(*fdf);
}

void	zoom(t_instance *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
	{
		if (fdf->grid.size < 75)
			fdf->grid.size += 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
	{
		if (fdf->grid.size > 2)
			fdf->grid.size -= 1;
	}
	execute_move(fdf);
}

