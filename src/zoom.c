#include "../include/fdf.h"

static void	execute_move(t_instance *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	project_map(*fdf);
}

// void	scroll(mlx_keyfunc *func, void *param)
// {
// 	t_instance	*fdf;

// 	fdf = (t_instance *)param;

// 	if (func)
// 		return ;
// }

void	zoom(t_instance *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
	{
		if (fdf->grid.size < 75)
			fdf->grid.size += 1;
		execute_move(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
	{
		if (fdf->grid.size > 2)
			fdf->grid.size -= 1;
		execute_move(fdf);
	}
}
