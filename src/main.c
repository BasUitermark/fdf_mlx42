/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 16:02:10 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/06 10:17:51 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*==============================================================================
 * Int main checks for argument count and initializes the fdf instance.
 * It further handles the map parsing function, image setup,
 * grid initialization, initial map projection, checks keyhooks, puts
 * instructions on screen and loops the function.
 * 
 * Main expects 1 argument; that is the relative path to a ".fdf" map file
 * in the "/maps" folder.
=============================================================================*/

static void	put_instructions(t_instance fdf)
{
	int	x;
	int	y;

	x = 10;
	y = 10;
	mlx_put_string(fdf.mlx, "Instructions:", x, y);
	mlx_put_string(fdf.mlx, "Move map:       W/A/S/D", x, y += 20);
	mlx_put_string(fdf.mlx, "Zoom:           Q/E", x, y += 20);
	mlx_put_string(fdf.mlx, "Rotate X axis:  R/T", x, y += 20);
	mlx_put_string(fdf.mlx, "Rotate Y axis:  F/G", x, y += 20);
	mlx_put_string(fdf.mlx, "Rotate Z axis:  V/B", x, y += 20);
	mlx_put_string(fdf.mlx, "Reset map:      0", x, y += 20);
}

static bool	initialize(mlx_t **mlx, char *title)
{
	*mlx = mlx_init(WIDTH, HEIGHT, title, TRUE);
	if (!mlx)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char const **argv)
{
	t_instance	fdf;

	if (argc != 2)
		error("Wrong map input!");
	if (initialize(&fdf.mlx, "FdF"))
	{
		fdf.map = parse_map(argv[1]);
		fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
		initialize_grid(&fdf);
		put_instructions(fdf);
		project_map(fdf);
		mlx_loop_hook(fdf.mlx, &key_hooks, &fdf);
		mlx_loop_hook(fdf.mlx, &close_hook, &fdf);
		mlx_loop(fdf.mlx);
	}
	error("Failed to initialize FdF");
}

/* TODO
 * Check for leaks and malloc protections.
 * Finish up documentation.
*/