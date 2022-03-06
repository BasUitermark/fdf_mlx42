#include "fdf.h"

static void	pixelput(t_data *data, t_coord coord, int color)
{
	char	*dst;

	dst = data->addr + (coord.y * data->line_length + coord.x * \
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
	incr->x = ft_axis(start.x, end.x);
	incr->y = ft_axis(start.y, end.y);
}

void	draw_line(t_init *init, t_coord start, t_coord end)
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
		pixelput(&init->img, cur, 0xFFFFFF);
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
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img.img, 0, 0);
}
