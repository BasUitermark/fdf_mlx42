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
		mlx_loop_hook(fdf.mlx, &key_hooks, fdf.mlx);
		mlx_loop(fdf.mlx);
		mlx_terminate(fdf.mlx);
	}
	return (0);
}

// static void	print_struct(t_map map)
// {
// 	int	i = 0;
// 	int	j = 0;

// 	printf("Width: %d\nDepth: %d\n", map.map_width, map.map_height);
// 	while (i < (map.map_height * map.map_width))
// 	{
// 		while (j < map.map_width)
// 		{
// 			printf("%d ", map.map_points[i]);
// 			j++;
// 			i++;
// 		}
// 		printf("\n");
// 		j = 0;
// 	}
// }

// int	main(int argc, char const **argv)
// {
// 	t_instance	fdf;

// 	fdf.map = parse_map("../maps/t1.fdf");
// 	print_struct(fdf.map);
// }

//TODO
/*
* Clean up files and improve naming
* Check protections
*/