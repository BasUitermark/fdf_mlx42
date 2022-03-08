#include "../include/fdf.h"

static int	axis(int start, int end)
{
	if (end < start)
		return (1);
	else
		return (-1);
}

static void	setup(t_coord start, t_coord end, t_coord *diff, t_coord *incr)
{
	diff->x = ft_abs(start.x - end.x);
	diff->y = ft_abs(start.y - end.y);
	incr->x = axis(start.x, end.x);
	incr->y = axis(start.y, end.y);
}

void	draw_line(mlx_t *mlx, mlx_image_t *img, t_coord start, t_coord end)
{
	t_coord	diff;
	t_coord	incr;
	t_coord	cur;
	int		boundary_value;

	setup(start, end, &diff, &incr);
	boundary_value = 2 * (diff.y - diff.x);
	cur = end;
	while (true)
	{
		mlx_put_pixel(img, cur.x, cur.y, 0xFFFFFF);
		if (cur.x == start.x && cur.y == start.y)
			break ;
		if (boundary_value >= 0)
		{
			cur.y += incr.y;
			boundary_value -= 2 * diff.x;
		}
		if (boundary_value < 0)
		{
			cur.x += incr.x;
			boundary_value += 2 * diff.y;
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
}
