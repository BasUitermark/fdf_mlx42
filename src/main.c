#include "fdf.h"

int	main(int argc, char const *argv)
{
	t_mlx_data	mlx;

	if (argc != 2)
		error("Wrong map input!");
	if (initialize(&mlx, WIDTH, HEIGHT, "FdF"))
	{
		mlx.img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
		if (!mlx.img.img)
			return (0);
		mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, \
					&mlx.img.line_length, &mlx.img.endian);
		if (!mlx.img.addr)
			return (0);
		mlx_key_hook(mlx.win, key_hooks, &mlx);
	}
	return (0);
}
