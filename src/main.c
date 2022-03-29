#include "../include/fdf.h"

/*==============================================================================
 * Int main checks for argument count and initializes the fdf instance.
 * It further handles the map parsing function, image setup, 
 * grid initialization, initial map projection, checks keyhooks
 * and loops the function.
 * 
 * Main expects 1 argument; that is the relative path to a ".fdf" map file
 * in the "/maps" folder.
=============================================================================*/

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
		project_map(fdf);
		mlx_loop_hook(fdf.mlx, &key_hooks, &fdf);
		mlx_loop_hook(fdf.mlx, &close_hook, &fdf);
		mlx_loop(fdf.mlx);
	}
	error("Failed to initialize FdF");
}

/* TODO
 * Clean up code and files.
 * Setup naming scheme.
 * Check for leaks and malloc protections.
 * Finish up documentation.
*/