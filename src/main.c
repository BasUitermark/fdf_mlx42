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
		project_map(fdf);
		mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
		mlx_loop_hook(fdf.mlx, &key_hooks, fdf.mlx);
		mlx_loop(fdf.mlx);
		mlx_terminate(fdf.mlx);
	}
	return (0);
}
