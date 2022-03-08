#include "../include/fdf.h"

int	main(int argc, char const **argv)
{
	mlx_t		*mlx;
	t_map		map;
	mlx_image_t	*img;

	img = NULL;
	if (argc != 2)
		error("Wrong map input!");
	if (initialize(&mlx, "FdF"))
	{
		map = parse_map(argv[1]);
		project_map(mlx, img, map);
		mlx_loop_hook(mlx, &key_hooks, mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	return (0);
}
