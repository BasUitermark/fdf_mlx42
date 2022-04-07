/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_projection.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 16:02:15 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/06 09:49:02 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*==============================================================================
 * project_map generates a starting point with a nested while loop and initiates
 * the grid drawing. draw grid then draws a line to the right and down, and
 * calculates an offset through calc_coord.
 * 
 * get_height simply looks for the appropriate point in map.points by the product
 * y and map.width, which gives the row. Adding x gives the appropriate number in
 * the row. z_offset then normalizes the map point to be within the window size.
=============================================================================*/

t_coord	translate_coord(int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

static int	get_height(t_instance fdf, int x, int y)
{
	return (fdf.map.points[y * fdf.map.width + x] * fdf.grid.z_offset);
}

static void	draw_grid(int x, int y, t_instance fdf)
{
	if (x != fdf.map.width - 1)
		draw_line(fdf.img, calc_coord(fdf, x, y, get_height(fdf, x, y)), \
		calc_coord(fdf, x + 1, y, get_height(fdf, x + 1, y)));
	if (y != fdf.map.height - 1)
		draw_line(fdf.img, calc_coord(fdf, x, y, get_height(fdf, x, y)), \
		calc_coord(fdf, x, y + 1, get_height(fdf, x, y + 1)));
}

void	project_map(t_instance fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf.map.height)
	{
		while (x < fdf.map.width)
		{
			draw_grid(x, y, fdf);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
}
