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

typedef struct s_grid
{
	int		size;
	int		x_offset;
	int		y_offset;
	int		z_offset;
	double	height_mod;
}	t_grid;

typedef struct s_instance
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_grid		grid;
}	t_instance;

//== Functions ==//

int		main(int argc, char const **argv);
int		initialize(mlx_t **mlx, char *title);
t_map	parse_map(const char *filepath);
void	error(char *error_msg);
void	initialize_grid(t_instance *fdf);
void	draw_line(mlx_image_t *img, t_coord start, t_coord end);
void	project_map(t_instance fdf);
void	close_hook(void *param);
void	key_hooks(void *param);
void	location(t_instance *fdf);
void	scroll(mlx_keyfunc *func, void *param);
void	zoom(t_instance *fdf);

#endif
