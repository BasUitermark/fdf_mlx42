#include "fdf.h"

int	main(int argc, char const **argv)
{
	mlx_t	*mlx;

	if (argc != 2)
		error("Wrong map input!");
	if (initialize(&mlx, WIDTH, HEIGHT, "FdF"))
	{
		mlx = mlx_new_image(mlx, WIDTH, HEIGHT);
		mlx_key_hook(mlx, key_hooks, mlx);
		mlx_loop(mlx);
	}
	return (0);
}
