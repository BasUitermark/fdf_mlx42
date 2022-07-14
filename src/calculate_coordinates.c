/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_coordinates.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 16:02:16 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/07 12:42:28 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	x_rotation(int *y, int *z, double x_rot)
{
	int	temp_y;
	int	temp_z;

	temp_y = *y;
	temp_z = *z;
	*y = temp_y * cos(x_rot) + temp_z * sin(x_rot);
	*z = -temp_y * sin(x_rot) + temp_z * cos(x_rot);
}

static void	y_rotation(int *x, int *z, double y_rot)
{
	int	temp_x;
	int	temp_z;

	temp_x = *x;
	temp_z = *z;
	*x = temp_x * cos(y_rot) + temp_z * sin(y_rot);
	*z = -temp_x * sin(y_rot) + temp_z * cos(y_rot);
}

static void	z_rotation(int *x, int *y, double z_rot)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = temp_x * cos(z_rot) - temp_y * sin(z_rot);
	*y = temp_x * sin(z_rot) + temp_y * cos(z_rot);
}

static void	iso_rotation(int *x, int *y)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(0.5);
	*y = (temp_x + temp_y) * sin(0.5);
}

t_coord	calc_coord(t_instance fdf, int x, int y, int z)
{
	x *= fdf.grid.size;
	y *= fdf.grid.size;
	x_rotation(&y, &z, fdf.grid.x_rot);
	y_rotation(&x, &z, fdf.grid.y_rot);
	z_rotation(&x, &y, fdf.grid.z_rot);
	iso_rotation(&x, &y);
	x += WIDTH / 2 - fdf.grid.x_offset;
	y += -z + HEIGHT / 2 - fdf.grid.y_offset;
	return (translate_coord(x, y));
}
