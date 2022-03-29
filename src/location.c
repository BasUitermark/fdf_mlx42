#include "../include/fdf.h"

static void	execute_move(t_instance *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	project_map(*fdf);
}

void	location(t_instance *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->grid.y_offset += (1 * fdf->grid.size);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->grid.y_offset -= (1 * fdf->grid.size);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->grid.x_offset += (1 * fdf->grid.size);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->grid.x_offset -= (1 * fdf->grid.size);
	execute_move(fdf);
}
