#include "fdf.h"

int	main(void)
{
	t_init	init;

	init.mlx = mlx_init();
	init.mlx_win = mlx_new_window(init.mlx, WIDTH, HEIGHT, "TEST");
	init.img.img = mlx_new_image(init.mlx, WIDTH, HEIGHT);
	init.img.addr = mlx_get_data_addr(init.img.img, &init.img.bits_per_pixel, \
				&init.img.line_length, &init.img.endian);
	draw_line(&init, start, end);
	mlx_loop(init.mlx);
	return (0);
}
