#include "../include/fdf.h"

static void	execute_move(t_instance *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	project_map(*fdf);
}

static void	reset_rot(t_instance *fdf)
{
	fdf->grid.x_rot = 0;
	fdf->grid.y_rot = 0;
	fdf->grid.z_rot = 0;
}

void	rotation(t_instance *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_R))
		fdf->grid.x_rot -= 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_T))
		fdf->grid.x_rot += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_F))
		fdf->grid.y_rot -= 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_G))
		fdf->grid.y_rot += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_V))
		fdf->grid.z_rot -= 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_B))
		fdf->grid.z_rot += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
		reset_rot(fdf);
	execute_move(fdf);
}

