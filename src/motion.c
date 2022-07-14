/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   motion.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 16:02:01 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/12 10:06:48 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	execute_move(t_instance *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
	{
		free (fdf->map.points);
		error("Failed to generate new image!");
	}
	project_map(*fdf);
}

void	location(t_instance *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->grid.y_offset -= 1.5 * fdf->grid.size;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->grid.y_offset += 1.5 * fdf->grid.size;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->grid.x_offset -= 1.5 * fdf->grid.size;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->grid.x_offset += 1.5 * fdf->grid.size;
	execute_move(fdf);
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
		initialize_grid(fdf);
	execute_move(fdf);
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
