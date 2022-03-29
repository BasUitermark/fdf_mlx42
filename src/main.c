#include "../include/fdf.h"

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
