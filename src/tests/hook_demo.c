#include "fdf.h"

int	main(void)
{
	t_mlx_data	item;

	item.mlx = mlx_init();
	item.win = mlx_new_window(item.mlx, 640, 480, "keyhook");
	mlx_key_hook(item.win, key_hooks, &item);
	mlx_loop(item.mlx);
}
