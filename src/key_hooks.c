/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 10:18:02 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/06 17:05:30 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hooks(void *param)
{
	t_instance	*fdf;

	fdf = (t_instance *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_A) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_S) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		location(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		zoom(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_R) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_T) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_F) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_G) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_V) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_B) || \
	mlx_is_key_down(fdf->mlx, MLX_KEY_0))
		rotation(fdf);
}

void	close_hook(void *param)
{
	t_instance	*fdf;

	fdf = (t_instance *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fdf->mlx);
		mlx_terminate(fdf->mlx);
		free (fdf->map.points);
		exit(EXIT_SUCCESS);
	}
}
