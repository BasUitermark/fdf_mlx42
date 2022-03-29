#include "../include/fdf.h"

/*
 * Initialize sets up the mlx_t instance with the height,
 * width and title of the window.
 * It also returns 
*/

bool	initialize(mlx_t **mlx, char *title)
{
	*mlx = mlx_init(WIDTH, HEIGHT, title, TRUE);
	if (!mlx)
		return (FALSE);
	return (TRUE);
}
