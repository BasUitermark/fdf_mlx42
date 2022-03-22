#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include "../include/MLX42/include/MLX42/MLX42.h"
# include "../include/libft/include/libft.h"
# include <stdio.h> //DELETE THIS
# define WIDTH 1920
# define HEIGHT 1080
# define GRIDSIZE 25

//== Structs ==//

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	int	*map_points;
	int	map_width;
	int	map_height;
}	t_map;

typedef struct s_instance
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_instance;

//== Functions ==//

int		main(int argc, char const **argv);
void	draw_line(mlx_t *mlx, mlx_image_t *img, t_coord start, t_coord end);
t_map	parse_map(const char *filepath);
void	error(char *error_msg);
void	key_hooks(void *param);
int		initialize(mlx_t **mlx, char *title);
void	project_map(t_instance fdf);

#endif
